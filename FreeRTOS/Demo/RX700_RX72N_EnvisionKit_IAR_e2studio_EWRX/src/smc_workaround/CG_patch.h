#ifndef CG_PATCH_H
#define CG_PATCH_H

/* Workaround for warning messages caused by missing function declaration.
 */
void r_undefined_exception(void);

/* Workaround for warning messages caused by missing 'void' argument prototype.
 */
void R_CGC_Create_UserInit(void);
////#define R_CGC_Create_UserInit() R_CGC_Create_UserInit(void)

#else /* CG_PATCH_H */

////#if defined(CG_USER_DEF_H)
////
/////* Workaround for warning messages caused by missing 'void' argument prototype.
//// */
////#undef R_CGC_Create_UserInit
////
////#endif /* defined(CG_USER_DEF_H) */

#endif /* CG_PATCH_H */
