import cpp

/**
 * @name Detect strcpy with potential buffer overflow
 * @description This query detects instances where strcpy is used to copy a string into a buffer that is smaller than the source string.
 * @kind problem
 * @problem.severity error
 * @id cpp/strcpy-buffer-overflow
 */

from FunctionCall strcpyCall, VariableAccess sourceVar, VariableAccess destVar, ArrayType sourceArrayType, ArrayType destArrayType
where
  strcpyCall.getTarget().hasName("strcpy") and
  strcpyCall.getArgument(0) = destVar and
  strcpyCall.getArgument(1) = sourceVar and
  sourceVar.getType() = sourceArrayType and
  destVar.getType() = destArrayType and
  sourceArrayType.getArraySize() > destArrayType.getArraySize()
select strcpyCall, sourceVar, destVar,
  sourceArrayType.getArraySize().toString() + " bytes copied into " +
  destArrayType.getArraySize().toString() + " bytes buffer"