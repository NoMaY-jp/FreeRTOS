# CS+ startup python script

ThrowExceptSave = common.ThrowExcept
common.ThrowExcept = True
try:
    if ScriptStarted == True:
        pass
except:
    ScriptStarted = False
common.ThrowExcept = ThrowExceptSave
del ThrowExceptSave

if ScriptStarted == False:
    ScriptStarted = True
    common.Hook(__file__)

def AfterDownload():
    ThrowExceptSave = common.ThrowExcept
    ViewOutputSave  = common.ViewOutput
    common.ThrowExcept = False
    common.ViewOutput  = False

    # Prepare a Breakpoint Object
    bp = BreakCondition()
    bp.Address = "_vAssertCalled"
    if debugger.DebugTool.GetType() != DebugTool.Simulator:
        bp.BreakType = BreakType.Software
    # Search an existing Breakpoint Object
    bi = None
    for bi in debugger.Breakpoint.Information():
        if bi.BreakType == bp.BreakType and bi.Address1 == bp.Address:
            break;
        else:
            bi = None
    # When it is found, re-create it keeping enabled/disabled to re-evaluate
    # the event address value of it. On the other hand, when it is not found,
    # create new one ENABLED.
    if bi != None:
        debugger.Breakpoint.Delete(bi.Number)
    bp_number = debugger.Breakpoint.Set(bp)
    if bi != None:
        if bi.Enable != True:
            debugger.Breakpoint.Disable(bp_number)

    common.ThrowExcept = ThrowExceptSave
    common.ViewOutput  = ViewOutputSave
    return

