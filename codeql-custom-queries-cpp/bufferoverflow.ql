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

class CallocCall extends FunctionCall {
    CallocCall() { this.getTarget().hasGlobalName("calloc") }

    Expr getAllocatedSize() {
        result = this.getArgument(0).mul(this.getArgument(1))
    }
}

class StrcpyCall extends FunctionCall {
    StrcpyCall() { this.getTarget().hasGlobalName("strcpy") }

    Expr getSourceString() {
        result = this.getArgument(1)
    }
}

from CallocCall calloc, StrcpyCall strcpy, Expr src, Expr dest
where
    strcpy.getSourceString() = src and
    strcpy.getArgument(0) = dest and
    dest.getAnAccess().getDefinition() = calloc.getAnAccess().getDefinition() and
    not calloc.getAllocatedSize().geq(src.getLength().add(1))
select strcpy, "Potential buffer overflow: allocated size does not match the size required for the copied string."