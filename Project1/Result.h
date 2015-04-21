#pragma once
class Result{
private:
	int result_type;
public:
	Result(int rt);
	virtual ~Result();

	int getCode() const;
};

