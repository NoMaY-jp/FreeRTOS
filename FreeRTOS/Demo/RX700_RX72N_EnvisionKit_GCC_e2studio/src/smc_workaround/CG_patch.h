#ifndef CG_PATCH_H
#define CG_PATCH_H

/* Workaround for warning messages caused by missing function declaration.
 */
void r_undefined_exception(void);

/* Workaround for warning messages caused by missing 'void' argument prototype.
 */
void R_CGC_Create_UserInit(void);

#endif /* CG_PATCH_H */
