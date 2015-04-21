#include "SearchMembersByReturnDate.h"


SearchMembersByReturnDate::SearchMembersByReturnDate(int cday, int cmonth, int cyear, int bday, int bmonth, int byear, Library *l) : current_date(cday, cmonth, cyear), borrowing_date(bday, bmonth, byear), SearchMembers(l){}


SearchMembersByReturnDate::~SearchMembersByReturnDate(){}


Result *SearchMembersByReturnDate::execute(){
	vector<File *> *fliks = new vector<File *>;

	MemberResult *mres = new MemberResult(fliks);
	MemberResult *m = new MemberResult(library->searchFilesByReturnDate(current_date, borrowing_date));
	return m;
}