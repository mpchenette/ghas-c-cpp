import cpp

/**
 * @name Use of strlen on TCHAR arrays
 * @description Detects the use of strlen on TCHAR arrays, which can lead to incorrect behavior if TCHAR is defined as wchar_t.
 * @kind problem
 * @problem.severity warning
 * @id cpp/strlen-on-tchar
 */

class TCHARType extends Type {
  TCHARType() {
    this.getUnspecifiedType().getName() = "TCHAR"
  }
}

from FunctionCall call, VariableAccess va, TCHARType tcharType
where
  call.getTarget().hasName("strlen") and
  va.getTarget().getType() = tcharType and
  call.getArgument(0) = va
select call, "Use of strlen on TCHAR arrays can lead to incorrect behavior if TCHAR is defined as wchar_t."