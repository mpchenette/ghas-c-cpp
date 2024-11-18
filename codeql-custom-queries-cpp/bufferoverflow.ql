import cpp
import semmle.code.cpp.dataflow.DataFlow

/**
 * @name Potential buffer overflow due to insufficient allocation
 * @description This query identifies cases where a buffer is allocated with insufficient size to hold a copied string, including the null terminator.
 * @kind problem
 * @problem.severity warning
 * @id cpp/buffer-overflow
 */
class InsufficientBufferAllocation extends DataFlow::Configuration {
// class InsufficientBufferAllocation extends TaintTracking::Configuration {
  InsufficientBufferAllocation() { this = "InsufficientBufferAllocation" }

  override predicate isSource(DataFlow::Node source) {
    exists(FunctionCall fc |
      fc.getTarget().hasName("OSacquire") and
      source.asExpr() = fc.getArgument(0)
    )
  }

  override predicate isSink(DataFlow::Node sink) {
    exists(FunctionCall fc |
      fc.getTarget().hasName("strcpy") and
      sink.asExpr() = fc.getArgument(0)
    )
  }

  // override predicate isSanitizer(DataFlow::Node sanitizer) {
  //   exists(FunctionCall fc |
  //     fc.getTarget().hasName("strlen") and
  //     sanitizer.asExpr() = fc.getArgument(0)
  //   )
  // }
}

from InsufficientBufferAllocation cfg, DataFlow::PathNode source, DataFlow::PathNode sink
where cfg.hasFlowPath(source, sink)
select sink.getNode(), "Potential buffer overflow due to insufficient allocation."