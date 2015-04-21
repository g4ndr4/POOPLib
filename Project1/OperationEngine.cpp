#include "OperationEngine.h"


OperationEngine::OperationEngine(){}


OperationEngine::~OperationEngine(){}

void OperationEngine::enableLogging(){}

void OperationEngine::undo(){}

Result *OperationEngine::submitOperation(Operation *o){
	return o->execute();
}