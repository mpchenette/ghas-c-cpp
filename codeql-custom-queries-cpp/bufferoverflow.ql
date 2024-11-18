/**
 * @kind problem
 * @id cpp/buffer-overflow
 * @name Buffer Overflow
 * @description Detects potential buffer overflow issues.
 * @severity error
 * @precision high
 * @tags maintainability
 *       readability
 *       security
 *       external/cwe/cwe-1078
 *       external/cwe/cwe-670
 */

import cpp
import semmle.code.cpp.controlflow.SSA

class MallocCall extends FunctionCall
{
    MallocCall() { this.getTarget().hasGlobalName("calloc") }

    Expr getAllocatedSize() {
        if this.getArgument(1) instanceof VariableAccess then
            exists(LocalScopeVariable v, SsaDefinition ssaDef |
                result = ssaDef.getAnUltimateDefiningValue(v)
                and this.getArgument(1) = ssaDef.getAUse(v))
        else
            result = this.getArgument(1)
    }
}

class StrcpyCall extends FunctionCall
{
    StrcpyCall() { this.getTarget().hasGlobalName("strcpy") }

    Expr getSource() { result = this.getArgument(1) }
    Expr getDestination() { result = this.getArgument(0) }
}

from StrcpyCall strcpy, MallocCall malloc, VariableAccess srcLen, VariableAccess allocSize
where
    strcpy.getSource() = srcLen and
    malloc.getAllocatedSize() = allocSize and
    srcLen.getType().getSize() + 1 > allocSize.getType().getSize()
select strcpy, "This allocation may cause a buffer overflow."