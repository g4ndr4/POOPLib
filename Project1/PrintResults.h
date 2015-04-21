#pragma once
#ifndef _PrintResults_H_
#define _PrintResults_H_
	#include "ViewingOperation.h"
	#include "Library.h"
	class PrintResults : public ViewingOperation{
	private:
		Result *result;
	public:
		PrintResults(Result *r, Library *l);
		~PrintResults();

		void log() override{};
		void undo() override{};
		Result *execute() override;
	};

#endif