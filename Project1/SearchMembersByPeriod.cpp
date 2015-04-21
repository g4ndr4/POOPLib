#include "SearchMembersByPeriod.h"


SearchMembersByPeriod::SearchMembersByPeriod(int bday, int bmonth, int byear, int eday, int emonth, int eyear, Library *l) : period_begin(bday, bmonth, byear), period_end(eday, emonth, eyear), SearchMembers(l){}


SearchMembersByPeriod::~SearchMembersByPeriod(){}


Result *SearchMembersByPeriod::execute(){
	return new MemberResult(library->searchFilesByPeriod(period_begin, period_end));
}
