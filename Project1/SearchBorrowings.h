#ifndef _B_H_
#define _B_H_
	#include "SearchingOperation.h"
	#include "Library.h"
	#include "BorrowingResult.h"
class SearchBorrowings : public SearchingOperation{
	private:
		int membership_id;
	public:
		SearchBorrowings(int mID, Library *l);
		~SearchBorrowings();

		void log() override{}
		void undo() override{}

		Result *execute() override;

};
#endif