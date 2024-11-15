/**
 * @name using strcpy instead of strncpy
 * @description If expressions before and after a comma operator use different indentation, it is easy to misread the purpose of the code.
 * @kind problem
 * @id cpp/strcpy-instead-of-strncpy
 * @problem.severity warning
 * @security-severity 7.8
 * @precision medium
 * @tags maintainability
 *       readability
 *       security
 *       external/cwe/cwe-1078
 *       external/cwe/cwe-670
 */

import cpp

from FunctionCall call
where call.getTarget().hasName("strcpy")
select call, "Consider using strncpy instead of strcpy."