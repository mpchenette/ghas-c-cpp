
/**
 * @kind problem
 * @id cpp/buffer-overflow
 * @name Buffer Overflow
 * @description Detects potential buffer overflow issues.
 * @severity error
 * @precision high
 */

import cpp
import semmle.code.cpp.controlflow.SSA

class MallocCall extends FunctionCall
{
    MallocCall() { this.getTarget().hasGlobalName("calloc") }

    Expr getAllocatedSize() {
        if this.getArgument(0) instanceof VariableAccess then
            exists(LocalScopeVariable v, SsaDefinition ssaDef |
                result = ssaDef.getAnUltimateDefiningValue(v)
                and this.getArgument(0) = ssaDef.getAUse(v))
        else
            result = this.getArgument(0)
    }
}

from MallocCall malloc
where malloc.getAllocatedSize() instanceof StrlenCall
select malloc, "This allocation does not include space to null-terminate the string."