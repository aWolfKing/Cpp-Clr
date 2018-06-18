#pragma once

using namespace System;

#define CONCAT2(s0, s1) s0##s1
#define CONCAT3(s0, s1, s2) s0##s1##s2
#define CONCAT4(s0, s1, s2, s3) s0##s1##s2##s3



#define VALUEPROPERTY1(datatype, valueID)property datatype valueID{\
		datatype get(){\
			return this->CONCAT2(value_, valueID);\
		}\
		void set(datatype value){\
			this->CONCAT2(value_, valueID) = value;\
		}\
	}\

#define VALUEPROPERTY2(datatype, valueID0, valueID1)property CONCAT2(datatype, 2) CONCAT2(valueID0, valueID1){\
		CONCAT2(datatype, 2) get(){\
			return CONCAT2(datatype, 2)(this->CONCAT2(value_, valueID0), this->CONCAT2(value_, valueID1));\
		}\
		void set(CONCAT2(datatype, 2) value){\
			this->CONCAT2(value_, valueID0) = value.CONCAT2(value_, x);\
			this->CONCAT2(value_, valueID1) = value.CONCAT2(value_, y);\
		}\
	}\

#define VALUEPROPERTY3(datatype, valueID0, valueID1, valueID2)property CONCAT2(datatype, 3) CONCAT3(valueID0, valueID1, valueID2) {\
		CONCAT2(datatype, 3) get(){\
			return CONCAT2(datatype, 3)(this->CONCAT2(value_, valueID0), this->CONCAT2(value_, valueID1), this->CONCAT2(value_, valueID2));\
		}\
		void set(CONCAT2(datatype, 3) value){\
			this->CONCAT2(value_, valueID0) = value.CONCAT2(value_, x);\
			this->CONCAT2(value_, valueID1) = value.CONCAT2(value_, y);\
			this->CONCAT2(value_, valueID2) = value.CONCAT2(value_, z);\
		}\
	}\

#define VALUEPROPERTY4(datatype, valueID0, valueID1, valueID2, valueID3)property CONCAT2(datatype, 4) CONCAT4(valueID0, valueID1, valueID2, valueID3) {\
		CONCAT2(datatype, 4) get(){\
			return CONCAT2(datatype, 4)(this->CONCAT2(value_, valueID0), this->CONCAT2(value_, valueID1), this->CONCAT2(value_, valueID2), this->CONCAT2(value_, valueID3));\
		}\
		void set(CONCAT2(datatype, 4) value){\
			this->CONCAT2(value_, valueID0) = value.CONCAT2(value_, x);\
			this->CONCAT2(value_, valueID1) = value.CONCAT2(value_, y);\
			this->CONCAT2(value_, valueID2) = value.CONCAT2(value_, z);\
			this->CONCAT2(value_, valueID3) = value.CONCAT2(value_, w);\
		}\
	}\



#define DATATYPE2(datatype) public value struct CONCAT2(datatype, 2) {\
internal:\
	datatype value_x;\
	datatype value_y;\
public:\
	property datatype default[int]{\
		datatype get(int index){\
			switch (index)\
			{\
			case 0:\
				return this->value_x;\
			case 1:\
				return this->value_y;\
			default:\
				throw gcnew System::IndexOutOfRangeException();\
			}\
		}\
		void set(int index, datatype value){\
			switch (index)\
			{\
			case 0:\
				this->value_x = value;\
			case 1:\
				this->value_y = value;\
			default:\
				throw gcnew System::IndexOutOfRangeException();\
			}\
		}\
	}\
	VALUEPROPERTY1(datatype, x)\
	VALUEPROPERTY1(datatype, y)\
	VALUEPROPERTY2(datatype, x, x)\
	VALUEPROPERTY2(datatype, x, y)\
	VALUEPROPERTY2(datatype, y, x)\
	VALUEPROPERTY2(datatype, y, y)\
	static operator CONCAT2(datatype, 2)(datatype value){\
		return CONCAT2(datatype, 2)(value, value);\
	}\
	static CONCAT2(datatype, 2) operator + (CONCAT2(datatype, 2) value0, datatype value1){\
		return CONCAT2(datatype, 2)(value0.CONCAT2(value_, x) + value1, value0.CONCAT2(value_, y) + value1);\
	}\
	static CONCAT2(datatype, 2) operator + (CONCAT2(datatype, 2) value0, CONCAT2(datatype, 2) value1){\
		return CONCAT2(datatype, 2)(value0.CONCAT2(value_, x) + value1.CONCAT2(value_, x), value0.CONCAT2(value_, y) + value1.CONCAT2(value_, y));\
	}\
	static CONCAT2(datatype, 2) operator - (CONCAT2(datatype, 2) value0, datatype value1){\
		return CONCAT2(datatype, 2)(value0.CONCAT2(value_, x) - value1, value0.CONCAT2(value_, y) - value1);\
	}\
	static CONCAT2(datatype, 2) operator - (CONCAT2(datatype, 2) value0, CONCAT2(datatype, 2) value1){\
		return CONCAT2(datatype, 2)(value0.CONCAT2(value_, x) - value1.CONCAT2(value_, x), value0.CONCAT2(value_, y) - value1.CONCAT2(value_, y));\
	}\
	static CONCAT2(datatype, 2) operator - (CONCAT2(datatype, 2) value){\
		return CONCAT2(datatype, 2)(-value.CONCAT2(value_, x), -value.CONCAT2(value_, y));\
	}\
	static CONCAT2(datatype, 2) operator * (CONCAT2(datatype, 2) value0, datatype value1){\
		return CONCAT2(datatype, 2)(value0.CONCAT2(value_, x) * value1, value0.CONCAT2(value_, y) * value1);\
	}\
	static CONCAT2(datatype, 2) operator / (CONCAT2(datatype, 2) value0, datatype value1){\
		if(value1 == 0){\
			throw gcnew System::DivideByZeroException();\
		}\
		return CONCAT2(datatype, 2)(value0.CONCAT2(value_, x) / value1, value0.CONCAT2(value_, y) / value1);\
	}\
	static bool operator != (CONCAT2(datatype, 2) value0, CONCAT2(datatype, 2) value1){\
		return value0.CONCAT2(value_, x) != value1.CONCAT2(value_, x) || value0.CONCAT2(value_, y) != value1.CONCAT2(value_, y);\
	}\
	static bool operator == (CONCAT2(datatype, 2) value0, CONCAT2(datatype, 2) value1){\
		return value0.CONCAT2(value_, x) == value1.CONCAT2(value_, x) && value0.CONCAT2(value_, y) == value1.CONCAT2(value_, y);\
	}\
	static bool operator != (CONCAT2(datatype, 2) value0, datatype value1){\
		return value0.CONCAT2(value_, x) != value1 || value0.CONCAT2(value_, y) != value1;\
	}\
	static bool operator == (CONCAT2(datatype, 2) value0, datatype value1){\
		return value0.CONCAT2(value_, x) == value1 && value0.CONCAT2(value_, y) == value1;\
	}\
	CONCAT2(datatype, 2)(datatype x, datatype y){\
		this->CONCAT2(value_, x) = x;\
		this->CONCAT2(value_, y) = y;\
	}\
	CONCAT2(datatype, 2)(datatype value){\
		this->CONCAT2(value_, x) = value;\
		this->CONCAT2(value_, y) = value;\
	}\
};



#define DATATYPE3(datatype) public value struct CONCAT2(datatype, 3) {\
internal:\
	datatype value_x;\
	datatype value_y;\
	datatype value_z;\
public:\
	property datatype default[int]{\
		datatype get(int index){\
			switch (index)\
			{\
			case 0:\
				return this->value_x;\
			case 1:\
				return this->value_y;\
			case 2:\
				return this->value_z;\
			default:\
				throw gcnew System::IndexOutOfRangeException();\
			}\
		}\
		void set(int index, datatype value){\
			switch (index)\
			{\
			case 0:\
				this->value_x = value;\
			case 1:\
				this->value_y = value;\
			case 2:\
				this->value_z = value;\
			default:\
				throw gcnew System::IndexOutOfRangeException();\
			}\
		}\
	}\
	VALUEPROPERTY1(datatype, x)\
	VALUEPROPERTY1(datatype, y)\
	VALUEPROPERTY1(datatype, z)\
	VALUEPROPERTY2(datatype, x, x)\
	VALUEPROPERTY2(datatype, x, y)\
	VALUEPROPERTY2(datatype, x, z)\
	VALUEPROPERTY2(datatype, y, x)\
	VALUEPROPERTY2(datatype, y, y)\
	VALUEPROPERTY2(datatype, y, z)\
	VALUEPROPERTY2(datatype, z, x)\
	VALUEPROPERTY2(datatype, z, y)\
	VALUEPROPERTY2(datatype, z, z)\
	VALUEPROPERTY3(datatype, x, x, x)\
	VALUEPROPERTY3(datatype, x, x, y)\
	VALUEPROPERTY3(datatype, x, x, z)\
	VALUEPROPERTY3(datatype, x, y, x)\
	VALUEPROPERTY3(datatype, x, y, y)\
	VALUEPROPERTY3(datatype, x, y, z)\
	VALUEPROPERTY3(datatype, x, z, x)\
	VALUEPROPERTY3(datatype, x, z, y)\
	VALUEPROPERTY3(datatype, x, z, z)\
	VALUEPROPERTY3(datatype, y, x, x)\
	VALUEPROPERTY3(datatype, y, x, y)\
	VALUEPROPERTY3(datatype, y, x, z)\
	VALUEPROPERTY3(datatype, y, y, x)\
	VALUEPROPERTY3(datatype, y, y, y)\
	VALUEPROPERTY3(datatype, y, y, z)\
	VALUEPROPERTY3(datatype, y, z, x)\
	VALUEPROPERTY3(datatype, y, z, y)\
	VALUEPROPERTY3(datatype, y, z, z)\
	VALUEPROPERTY3(datatype, z, x, x)\
	VALUEPROPERTY3(datatype, z, x, y)\
	VALUEPROPERTY3(datatype, z, x, z)\
	VALUEPROPERTY3(datatype, z, y, x)\
	VALUEPROPERTY3(datatype, z, y, y)\
	VALUEPROPERTY3(datatype, z, y, z)\
	VALUEPROPERTY3(datatype, z, z, x)\
	VALUEPROPERTY3(datatype, z, z, y)\
	VALUEPROPERTY3(datatype, z, z, z)\
	static operator CONCAT2(datatype, 3)(datatype value){\
		return CONCAT2(datatype, 3)(value, value, value);\
	}\
	static CONCAT2(datatype, 3) operator + (CONCAT2(datatype, 3) value0, datatype value1){\
		return CONCAT2(datatype, 3)(value0.CONCAT2(value_, x) + value1, value0.CONCAT2(value_, y) + value1, value0.CONCAT2(value_, z) + value1);\
	}\
	static CONCAT2(datatype, 3) operator + (CONCAT2(datatype, 3) value0, CONCAT2(datatype, 3) value1){\
		return CONCAT2(datatype, 3)(value0.CONCAT2(value_, x) + value1.CONCAT2(value_, x), value0.CONCAT2(value_, y) + value1.CONCAT2(value_, y), value0.CONCAT2(value_, z) + value1.CONCAT2(value_, z));\
	}\
	static CONCAT2(datatype, 3) operator - (CONCAT2(datatype, 3) value0, datatype value1){\
		return CONCAT2(datatype, 3)(value0.CONCAT2(value_, x) - value1, value0.CONCAT2(value_, y) - value1, value0.CONCAT2(value_, z) - value1);\
	}\
	static CONCAT2(datatype, 3) operator - (CONCAT2(datatype, 3) value0, CONCAT2(datatype, 3) value1){\
		return CONCAT2(datatype, 3)(value0.CONCAT2(value_, x) - value1.CONCAT2(value_, x), value0.CONCAT2(value_, y) - value1.CONCAT2(value_, y), value0.CONCAT2(value_, z) - value1.CONCAT2(value_, z));\
	}\
	static CONCAT2(datatype, 3) operator - (CONCAT2(datatype, 3) value){\
		return CONCAT2(datatype, 3)(-value.CONCAT2(value_, x), -value.CONCAT2(value_, y), -value.CONCAT2(value_, z));\
	}\
	static CONCAT2(datatype, 3) operator * (CONCAT2(datatype, 3) value0, datatype value1){\
		return CONCAT2(datatype, 3)(value0.CONCAT2(value_, x) * value1, value0.CONCAT2(value_, y) * value1, value0.CONCAT2(value_, z) * value1);\
	}\
	static CONCAT2(datatype, 3) operator / (CONCAT2(datatype, 3) value0, datatype value1){\
		if(value1 == 0){\
			throw gcnew System::DivideByZeroException();\
		}\
		return CONCAT2(datatype, 3)(value0.CONCAT2(value_, x) / value1, value0.CONCAT2(value_, y) / value1, value0.CONCAT2(value_, z) / value1);\
	}\
	static bool operator != (CONCAT2(datatype, 3) value0, CONCAT2(datatype, 3) value1){\
		return value0.CONCAT2(value_, x) != value1.CONCAT2(value_, x) || value0.CONCAT2(value_, y) != value1.CONCAT2(value_, y) || value0.CONCAT2(value_, z) != value1.CONCAT2(value_, z);\
	}\
	static bool operator == (CONCAT2(datatype, 3) value0, CONCAT2(datatype, 3) value1){\
		return value0.CONCAT2(value_, x) == value1.CONCAT2(value_, x) && value0.CONCAT2(value_, y) == value1.CONCAT2(value_, y) && value0.CONCAT2(value_, z) == value1.CONCAT2(value_, z);\
	}\
	static bool operator != (CONCAT2(datatype, 3) value0, datatype value1){\
		return value0.CONCAT2(value_, x) != value1 || value0.CONCAT2(value_, y) != value1 || value0.CONCAT2(value_, z) != value1;\
	}\
	static bool operator == (CONCAT2(datatype, 3) value0, datatype value1){\
		return value0.CONCAT2(value_, x) == value1 && value0.CONCAT2(value_, y) == value1 && value0.CONCAT2(value_, z) == value1;\
	}\
	CONCAT2(datatype, 3)(datatype x, datatype y, datatype z){\
		this->CONCAT2(value_, x) = x;\
		this->CONCAT2(value_, y) = y;\
		this->CONCAT2(value_, z) = z;\
	}\
	CONCAT2(datatype, 3)(datatype x, CONCAT2(datatype, 2) value){\
		this->CONCAT2(value_, x) = x;\
		this->CONCAT2(value_, y) = value.CONCAT2(value_, x);\
		this->CONCAT2(value_, z) = value.CONCAT2(value_, y);\
	}\
	CONCAT2(datatype, 3)(CONCAT2(datatype, 2) value, datatype z){\
		this->CONCAT2(value_, x) = value.CONCAT2(value_, x);\
		this->CONCAT2(value_, y) = value.CONCAT2(value_, y);\
		this->CONCAT2(value_, z) = z;\
	}\
	CONCAT2(datatype, 3)(datatype value){\
		this->CONCAT2(value_, x) = value;\
		this->CONCAT2(value_, y) = value;\
		this->CONCAT2(value_, z) = value;\
	}\
};



#define DATATYPE4(datatype) public value struct CONCAT2(datatype, 4) {\
internal:\
	datatype value_x;\
	datatype value_y;\
	datatype value_z;\
	datatype value_w;\
public:\
	property datatype default[int]{\
		datatype get(int index){\
			switch (index)\
			{\
			case 0:\
				return this->value_x;\
			case 1:\
				return this->value_y;\
			case 2:\
				return this->value_z;\
			case 3:\
				return this->value_w;\
			default:\
				throw gcnew System::IndexOutOfRangeException();\
			}\
		}\
		void set(int index, datatype value){\
			switch (index)\
			{\
			case 0:\
				this->value_x = value;\
			case 1:\
				this->value_y = value;\
			case 2:\
				this->value_z = value;\
			case 3:\
				this->value_w = value;\
			default:\
				throw gcnew System::IndexOutOfRangeException();\
			}\
		}\
	}\
	VALUEPROPERTY1(datatype, x)\
	VALUEPROPERTY1(datatype, y)\
	VALUEPROPERTY1(datatype, z)\
	VALUEPROPERTY1(datatype, w)\
	VALUEPROPERTY2(datatype, x, x)\
	VALUEPROPERTY2(datatype, x, y)\
	VALUEPROPERTY2(datatype, x, z)\
	VALUEPROPERTY2(datatype, x, w)\
	VALUEPROPERTY2(datatype, y, x)\
	VALUEPROPERTY2(datatype, y, y)\
	VALUEPROPERTY2(datatype, y, z)\
	VALUEPROPERTY2(datatype, y, w)\
	VALUEPROPERTY2(datatype, z, x)\
	VALUEPROPERTY2(datatype, z, y)\
	VALUEPROPERTY2(datatype, z, z)\
	VALUEPROPERTY2(datatype, z, w)\
	VALUEPROPERTY2(datatype, w, x)\
	VALUEPROPERTY2(datatype, w, y)\
	VALUEPROPERTY2(datatype, w, z)\
	VALUEPROPERTY2(datatype, w, w)\
	VALUEPROPERTY3(datatype, x, x, x)\
	VALUEPROPERTY3(datatype, x, x, y)\
	VALUEPROPERTY3(datatype, x, x, z)\
	VALUEPROPERTY3(datatype, x, x, w)\
	VALUEPROPERTY3(datatype, x, y, x)\
	VALUEPROPERTY3(datatype, x, y, y)\
	VALUEPROPERTY3(datatype, x, y, z)\
	VALUEPROPERTY3(datatype, x, y, w)\
	VALUEPROPERTY3(datatype, x, z, x)\
	VALUEPROPERTY3(datatype, x, z, y)\
	VALUEPROPERTY3(datatype, x, z, z)\
	VALUEPROPERTY3(datatype, x, z, w)\
	VALUEPROPERTY3(datatype, x, w, x)\
	VALUEPROPERTY3(datatype, x, w, y)\
	VALUEPROPERTY3(datatype, x, w, z)\
	VALUEPROPERTY3(datatype, x, w, w)\
	VALUEPROPERTY3(datatype, y, x, x)\
	VALUEPROPERTY3(datatype, y, x, y)\
	VALUEPROPERTY3(datatype, y, x, z)\
	VALUEPROPERTY3(datatype, y, x, w)\
	VALUEPROPERTY3(datatype, y, y, x)\
	VALUEPROPERTY3(datatype, y, y, y)\
	VALUEPROPERTY3(datatype, y, y, z)\
	VALUEPROPERTY3(datatype, y, y, w)\
	VALUEPROPERTY3(datatype, y, z, x)\
	VALUEPROPERTY3(datatype, y, z, y)\
	VALUEPROPERTY3(datatype, y, z, z)\
	VALUEPROPERTY3(datatype, y, z, w)\
	VALUEPROPERTY3(datatype, y, w, x)\
	VALUEPROPERTY3(datatype, y, w, y)\
	VALUEPROPERTY3(datatype, y, w, z)\
	VALUEPROPERTY3(datatype, y, w, w)\
	VALUEPROPERTY3(datatype, z, x, x)\
	VALUEPROPERTY3(datatype, z, x, y)\
	VALUEPROPERTY3(datatype, z, x, z)\
	VALUEPROPERTY3(datatype, z, x, w)\
	VALUEPROPERTY3(datatype, z, y, x)\
	VALUEPROPERTY3(datatype, z, y, y)\
	VALUEPROPERTY3(datatype, z, y, z)\
	VALUEPROPERTY3(datatype, z, y, w)\
	VALUEPROPERTY3(datatype, z, z, x)\
	VALUEPROPERTY3(datatype, z, z, y)\
	VALUEPROPERTY3(datatype, z, z, z)\
	VALUEPROPERTY3(datatype, z, z, w)\
	VALUEPROPERTY3(datatype, z, w, x)\
	VALUEPROPERTY3(datatype, z, w, y)\
	VALUEPROPERTY3(datatype, z, w, z)\
	VALUEPROPERTY3(datatype, z, w, w)\
	VALUEPROPERTY3(datatype, w, x, x)\
	VALUEPROPERTY3(datatype, w, x, y)\
	VALUEPROPERTY3(datatype, w, x, z)\
	VALUEPROPERTY3(datatype, w, x, w)\
	VALUEPROPERTY3(datatype, w, y, x)\
	VALUEPROPERTY3(datatype, w, y, y)\
	VALUEPROPERTY3(datatype, w, y, z)\
	VALUEPROPERTY3(datatype, w, y, w)\
	VALUEPROPERTY3(datatype, w, z, x)\
	VALUEPROPERTY3(datatype, w, z, y)\
	VALUEPROPERTY3(datatype, w, z, z)\
	VALUEPROPERTY3(datatype, w, z, w)\
	VALUEPROPERTY3(datatype, w, w, x)\
	VALUEPROPERTY3(datatype, w, w, y)\
	VALUEPROPERTY3(datatype, w, w, z)\
	VALUEPROPERTY3(datatype, w, w, w)\
	VALUEPROPERTY4(datatype, x, x, x, x)\
	VALUEPROPERTY4(datatype, x, x, x, y)\
	VALUEPROPERTY4(datatype, x, x, x, z)\
	VALUEPROPERTY4(datatype, x, x, x, w)\
	VALUEPROPERTY4(datatype, x, x, y, x)\
	VALUEPROPERTY4(datatype, x, x, y, y)\
	VALUEPROPERTY4(datatype, x, x, y, z)\
	VALUEPROPERTY4(datatype, x, x, y, w)\
	VALUEPROPERTY4(datatype, x, x, z, x)\
	VALUEPROPERTY4(datatype, x, x, z, y)\
	VALUEPROPERTY4(datatype, x, x, z, z)\
	VALUEPROPERTY4(datatype, x, x, z, w)\
	VALUEPROPERTY4(datatype, x, x, w, x)\
	VALUEPROPERTY4(datatype, x, x, w, y)\
	VALUEPROPERTY4(datatype, x, x, w, z)\
	VALUEPROPERTY4(datatype, x, x, w, w)\
	VALUEPROPERTY4(datatype, x, y, x, x)\
	VALUEPROPERTY4(datatype, x, y, x, y)\
	VALUEPROPERTY4(datatype, x, y, x, z)\
	VALUEPROPERTY4(datatype, x, y, x, w)\
	VALUEPROPERTY4(datatype, x, y, y, x)\
	VALUEPROPERTY4(datatype, x, y, y, y)\
	VALUEPROPERTY4(datatype, x, y, y, z)\
	VALUEPROPERTY4(datatype, x, y, y, w)\
	VALUEPROPERTY4(datatype, x, y, z, x)\
	VALUEPROPERTY4(datatype, x, y, z, y)\
	VALUEPROPERTY4(datatype, x, y, z, z)\
	VALUEPROPERTY4(datatype, x, y, z, w)\
	VALUEPROPERTY4(datatype, x, y, w, x)\
	VALUEPROPERTY4(datatype, x, y, w, y)\
	VALUEPROPERTY4(datatype, x, y, w, z)\
	VALUEPROPERTY4(datatype, x, y, w, w)\
	VALUEPROPERTY4(datatype, x, z, x, x)\
	VALUEPROPERTY4(datatype, x, z, x, y)\
	VALUEPROPERTY4(datatype, x, z, x, z)\
	VALUEPROPERTY4(datatype, x, z, x, w)\
	VALUEPROPERTY4(datatype, x, z, y, x)\
	VALUEPROPERTY4(datatype, x, z, y, y)\
	VALUEPROPERTY4(datatype, x, z, y, z)\
	VALUEPROPERTY4(datatype, x, z, y, w)\
	VALUEPROPERTY4(datatype, x, z, z, x)\
	VALUEPROPERTY4(datatype, x, z, z, y)\
	VALUEPROPERTY4(datatype, x, z, z, z)\
	VALUEPROPERTY4(datatype, x, z, z, w)\
	VALUEPROPERTY4(datatype, x, z, w, x)\
	VALUEPROPERTY4(datatype, x, z, w, y)\
	VALUEPROPERTY4(datatype, x, z, w, z)\
	VALUEPROPERTY4(datatype, x, z, w, w)\
	VALUEPROPERTY4(datatype, x, w, x, x)\
	VALUEPROPERTY4(datatype, x, w, x, y)\
	VALUEPROPERTY4(datatype, x, w, x, z)\
	VALUEPROPERTY4(datatype, x, w, x, w)\
	VALUEPROPERTY4(datatype, x, w, y, x)\
	VALUEPROPERTY4(datatype, x, w, y, y)\
	VALUEPROPERTY4(datatype, x, w, y, z)\
	VALUEPROPERTY4(datatype, x, w, y, w)\
	VALUEPROPERTY4(datatype, x, w, z, x)\
	VALUEPROPERTY4(datatype, x, w, z, y)\
	VALUEPROPERTY4(datatype, x, w, z, z)\
	VALUEPROPERTY4(datatype, x, w, z, w)\
	VALUEPROPERTY4(datatype, x, w, w, x)\
	VALUEPROPERTY4(datatype, x, w, w, y)\
	VALUEPROPERTY4(datatype, x, w, w, z)\
	VALUEPROPERTY4(datatype, x, w, w, w)\
	VALUEPROPERTY4(datatype, y, x, x, x)\
	VALUEPROPERTY4(datatype, y, x, x, y)\
	VALUEPROPERTY4(datatype, y, x, x, z)\
	VALUEPROPERTY4(datatype, y, x, x, w)\
	VALUEPROPERTY4(datatype, y, x, y, x)\
	VALUEPROPERTY4(datatype, y, x, y, y)\
	VALUEPROPERTY4(datatype, y, x, y, z)\
	VALUEPROPERTY4(datatype, y, x, y, w)\
	VALUEPROPERTY4(datatype, y, x, z, x)\
	VALUEPROPERTY4(datatype, y, x, z, y)\
	VALUEPROPERTY4(datatype, y, x, z, z)\
	VALUEPROPERTY4(datatype, y, x, z, w)\
	VALUEPROPERTY4(datatype, y, x, w, x)\
	VALUEPROPERTY4(datatype, y, x, w, y)\
	VALUEPROPERTY4(datatype, y, x, w, z)\
	VALUEPROPERTY4(datatype, y, x, w, w)\
	VALUEPROPERTY4(datatype, y, y, x, x)\
	VALUEPROPERTY4(datatype, y, y, x, y)\
	VALUEPROPERTY4(datatype, y, y, x, z)\
	VALUEPROPERTY4(datatype, y, y, x, w)\
	VALUEPROPERTY4(datatype, y, y, y, x)\
	VALUEPROPERTY4(datatype, y, y, y, y)\
	VALUEPROPERTY4(datatype, y, y, y, z)\
	VALUEPROPERTY4(datatype, y, y, y, w)\
	VALUEPROPERTY4(datatype, y, y, z, x)\
	VALUEPROPERTY4(datatype, y, y, z, y)\
	VALUEPROPERTY4(datatype, y, y, z, z)\
	VALUEPROPERTY4(datatype, y, y, z, w)\
	VALUEPROPERTY4(datatype, y, y, w, x)\
	VALUEPROPERTY4(datatype, y, y, w, y)\
	VALUEPROPERTY4(datatype, y, y, w, z)\
	VALUEPROPERTY4(datatype, y, y, w, w)\
	VALUEPROPERTY4(datatype, y, z, x, x)\
	VALUEPROPERTY4(datatype, y, z, x, y)\
	VALUEPROPERTY4(datatype, y, z, x, z)\
	VALUEPROPERTY4(datatype, y, z, x, w)\
	VALUEPROPERTY4(datatype, y, z, y, x)\
	VALUEPROPERTY4(datatype, y, z, y, y)\
	VALUEPROPERTY4(datatype, y, z, y, z)\
	VALUEPROPERTY4(datatype, y, z, y, w)\
	VALUEPROPERTY4(datatype, y, z, z, x)\
	VALUEPROPERTY4(datatype, y, z, z, y)\
	VALUEPROPERTY4(datatype, y, z, z, z)\
	VALUEPROPERTY4(datatype, y, z, z, w)\
	VALUEPROPERTY4(datatype, y, z, w, x)\
	VALUEPROPERTY4(datatype, y, z, w, y)\
	VALUEPROPERTY4(datatype, y, z, w, z)\
	VALUEPROPERTY4(datatype, y, z, w, w)\
	VALUEPROPERTY4(datatype, y, w, x, x)\
	VALUEPROPERTY4(datatype, y, w, x, y)\
	VALUEPROPERTY4(datatype, y, w, x, z)\
	VALUEPROPERTY4(datatype, y, w, x, w)\
	VALUEPROPERTY4(datatype, y, w, y, x)\
	VALUEPROPERTY4(datatype, y, w, y, y)\
	VALUEPROPERTY4(datatype, y, w, y, z)\
	VALUEPROPERTY4(datatype, y, w, y, w)\
	VALUEPROPERTY4(datatype, y, w, z, x)\
	VALUEPROPERTY4(datatype, y, w, z, y)\
	VALUEPROPERTY4(datatype, y, w, z, z)\
	VALUEPROPERTY4(datatype, y, w, z, w)\
	VALUEPROPERTY4(datatype, y, w, w, x)\
	VALUEPROPERTY4(datatype, y, w, w, y)\
	VALUEPROPERTY4(datatype, y, w, w, z)\
	VALUEPROPERTY4(datatype, y, w, w, w)\
	VALUEPROPERTY4(datatype, z, x, x, x)\
	VALUEPROPERTY4(datatype, z, x, x, y)\
	VALUEPROPERTY4(datatype, z, x, x, z)\
	VALUEPROPERTY4(datatype, z, x, x, w)\
	VALUEPROPERTY4(datatype, z, x, y, x)\
	VALUEPROPERTY4(datatype, z, x, y, y)\
	VALUEPROPERTY4(datatype, z, x, y, z)\
	VALUEPROPERTY4(datatype, z, x, y, w)\
	VALUEPROPERTY4(datatype, z, x, z, x)\
	VALUEPROPERTY4(datatype, z, x, z, y)\
	VALUEPROPERTY4(datatype, z, x, z, z)\
	VALUEPROPERTY4(datatype, z, x, z, w)\
	VALUEPROPERTY4(datatype, z, x, w, x)\
	VALUEPROPERTY4(datatype, z, x, w, y)\
	VALUEPROPERTY4(datatype, z, x, w, z)\
	VALUEPROPERTY4(datatype, z, x, w, w)\
	VALUEPROPERTY4(datatype, z, y, x, x)\
	VALUEPROPERTY4(datatype, z, y, x, y)\
	VALUEPROPERTY4(datatype, z, y, x, z)\
	VALUEPROPERTY4(datatype, z, y, x, w)\
	VALUEPROPERTY4(datatype, z, y, y, x)\
	VALUEPROPERTY4(datatype, z, y, y, y)\
	VALUEPROPERTY4(datatype, z, y, y, z)\
	VALUEPROPERTY4(datatype, z, y, y, w)\
	VALUEPROPERTY4(datatype, z, y, z, x)\
	VALUEPROPERTY4(datatype, z, y, z, y)\
	VALUEPROPERTY4(datatype, z, y, z, z)\
	VALUEPROPERTY4(datatype, z, y, z, w)\
	VALUEPROPERTY4(datatype, z, y, w, x)\
	VALUEPROPERTY4(datatype, z, y, w, y)\
	VALUEPROPERTY4(datatype, z, y, w, z)\
	VALUEPROPERTY4(datatype, z, y, w, w)\
	VALUEPROPERTY4(datatype, z, z, x, x)\
	VALUEPROPERTY4(datatype, z, z, x, y)\
	VALUEPROPERTY4(datatype, z, z, x, z)\
	VALUEPROPERTY4(datatype, z, z, x, w)\
	VALUEPROPERTY4(datatype, z, z, y, x)\
	VALUEPROPERTY4(datatype, z, z, y, y)\
	VALUEPROPERTY4(datatype, z, z, y, z)\
	VALUEPROPERTY4(datatype, z, z, y, w)\
	VALUEPROPERTY4(datatype, z, z, z, x)\
	VALUEPROPERTY4(datatype, z, z, z, y)\
	VALUEPROPERTY4(datatype, z, z, z, z)\
	VALUEPROPERTY4(datatype, z, z, z, w)\
	VALUEPROPERTY4(datatype, z, z, w, x)\
	VALUEPROPERTY4(datatype, z, z, w, y)\
	VALUEPROPERTY4(datatype, z, z, w, z)\
	VALUEPROPERTY4(datatype, z, z, w, w)\
	VALUEPROPERTY4(datatype, z, w, x, x)\
	VALUEPROPERTY4(datatype, z, w, x, y)\
	VALUEPROPERTY4(datatype, z, w, x, z)\
	VALUEPROPERTY4(datatype, z, w, x, w)\
	VALUEPROPERTY4(datatype, z, w, y, x)\
	VALUEPROPERTY4(datatype, z, w, y, y)\
	VALUEPROPERTY4(datatype, z, w, y, z)\
	VALUEPROPERTY4(datatype, z, w, y, w)\
	VALUEPROPERTY4(datatype, z, w, z, x)\
	VALUEPROPERTY4(datatype, z, w, z, y)\
	VALUEPROPERTY4(datatype, z, w, z, z)\
	VALUEPROPERTY4(datatype, z, w, z, w)\
	VALUEPROPERTY4(datatype, z, w, w, x)\
	VALUEPROPERTY4(datatype, z, w, w, y)\
	VALUEPROPERTY4(datatype, z, w, w, z)\
	VALUEPROPERTY4(datatype, z, w, w, w)\
	VALUEPROPERTY4(datatype, w, x, x, x)\
	VALUEPROPERTY4(datatype, w, x, x, y)\
	VALUEPROPERTY4(datatype, w, x, x, z)\
	VALUEPROPERTY4(datatype, w, x, x, w)\
	VALUEPROPERTY4(datatype, w, x, y, x)\
	VALUEPROPERTY4(datatype, w, x, y, y)\
	VALUEPROPERTY4(datatype, w, x, y, z)\
	VALUEPROPERTY4(datatype, w, x, y, w)\
	VALUEPROPERTY4(datatype, w, x, z, x)\
	VALUEPROPERTY4(datatype, w, x, z, y)\
	VALUEPROPERTY4(datatype, w, x, z, z)\
	VALUEPROPERTY4(datatype, w, x, z, w)\
	VALUEPROPERTY4(datatype, w, x, w, x)\
	VALUEPROPERTY4(datatype, w, x, w, y)\
	VALUEPROPERTY4(datatype, w, x, w, z)\
	VALUEPROPERTY4(datatype, w, x, w, w)\
	VALUEPROPERTY4(datatype, w, y, x, x)\
	VALUEPROPERTY4(datatype, w, y, x, y)\
	VALUEPROPERTY4(datatype, w, y, x, z)\
	VALUEPROPERTY4(datatype, w, y, x, w)\
	VALUEPROPERTY4(datatype, w, y, y, x)\
	VALUEPROPERTY4(datatype, w, y, y, y)\
	VALUEPROPERTY4(datatype, w, y, y, z)\
	VALUEPROPERTY4(datatype, w, y, y, w)\
	VALUEPROPERTY4(datatype, w, y, z, x)\
	VALUEPROPERTY4(datatype, w, y, z, y)\
	VALUEPROPERTY4(datatype, w, y, z, z)\
	VALUEPROPERTY4(datatype, w, y, z, w)\
	VALUEPROPERTY4(datatype, w, y, w, x)\
	VALUEPROPERTY4(datatype, w, y, w, y)\
	VALUEPROPERTY4(datatype, w, y, w, z)\
	VALUEPROPERTY4(datatype, w, y, w, w)\
	VALUEPROPERTY4(datatype, w, z, x, x)\
	VALUEPROPERTY4(datatype, w, z, x, y)\
	VALUEPROPERTY4(datatype, w, z, x, z)\
	VALUEPROPERTY4(datatype, w, z, x, w)\
	VALUEPROPERTY4(datatype, w, z, y, x)\
	VALUEPROPERTY4(datatype, w, z, y, y)\
	VALUEPROPERTY4(datatype, w, z, y, z)\
	VALUEPROPERTY4(datatype, w, z, y, w)\
	VALUEPROPERTY4(datatype, w, z, z, x)\
	VALUEPROPERTY4(datatype, w, z, z, y)\
	VALUEPROPERTY4(datatype, w, z, z, z)\
	VALUEPROPERTY4(datatype, w, z, z, w)\
	VALUEPROPERTY4(datatype, w, z, w, x)\
	VALUEPROPERTY4(datatype, w, z, w, y)\
	VALUEPROPERTY4(datatype, w, z, w, z)\
	VALUEPROPERTY4(datatype, w, z, w, w)\
	VALUEPROPERTY4(datatype, w, w, x, x)\
	VALUEPROPERTY4(datatype, w, w, x, y)\
	VALUEPROPERTY4(datatype, w, w, x, z)\
	VALUEPROPERTY4(datatype, w, w, x, w)\
	VALUEPROPERTY4(datatype, w, w, y, x)\
	VALUEPROPERTY4(datatype, w, w, y, y)\
	VALUEPROPERTY4(datatype, w, w, y, z)\
	VALUEPROPERTY4(datatype, w, w, y, w)\
	VALUEPROPERTY4(datatype, w, w, z, x)\
	VALUEPROPERTY4(datatype, w, w, z, y)\
	VALUEPROPERTY4(datatype, w, w, z, z)\
	VALUEPROPERTY4(datatype, w, w, z, w)\
	VALUEPROPERTY4(datatype, w, w, w, x)\
	VALUEPROPERTY4(datatype, w, w, w, y)\
	VALUEPROPERTY4(datatype, w, w, w, z)\
	VALUEPROPERTY4(datatype, w, w, w, w)\
	static operator CONCAT2(datatype, 4)(datatype value){\
		return CONCAT2(datatype, 4)(value, value, value, value);\
	}\
	static CONCAT2(datatype, 4) operator + (CONCAT2(datatype, 4) value0, datatype value1){\
		return CONCAT2(datatype, 4)(value0.CONCAT2(value_, x) + value1, value0.CONCAT2(value_, y) + value1, value0.CONCAT2(value_, z) + value1, value0.CONCAT2(value_, w) + value1);\
	}\
	static CONCAT2(datatype, 4) operator + (CONCAT2(datatype, 4) value0, CONCAT2(datatype, 4) value1){\
		return CONCAT2(datatype, 4)(value0.CONCAT2(value_, x) + value1.CONCAT2(value_, x), value0.CONCAT2(value_, y) + value1.CONCAT2(value_, y), value0.CONCAT2(value_, z) + value1.CONCAT2(value_, z), value0.CONCAT2(value_, z) + value1.CONCAT2(value_, w));\
	}\
	static CONCAT2(datatype, 4) operator - (CONCAT2(datatype, 4) value0, datatype value1){\
		return CONCAT2(datatype, 4)(value0.CONCAT2(value_, x) - value1, value0.CONCAT2(value_, y) - value1, value0.CONCAT2(value_, z) - value1, value0.CONCAT2(value_, w) - value1);\
	}\
	static CONCAT2(datatype, 4) operator - (CONCAT2(datatype, 4) value0, CONCAT2(datatype, 4) value1){\
		return CONCAT2(datatype, 4)(value0.CONCAT2(value_, x) - value1.CONCAT2(value_, x), value0.CONCAT2(value_, y) - value1.CONCAT2(value_, y), value0.CONCAT2(value_, z) - value1.CONCAT2(value_, z), value0.CONCAT2(value_, w) - value1.CONCAT2(value_, w));\
	}\
	static CONCAT2(datatype, 4) operator - (CONCAT2(datatype, 4) value){\
		return CONCAT2(datatype, 4)(-value.CONCAT2(value_, x), -value.CONCAT2(value_, y), -value.CONCAT2(value_, z), -value.CONCAT2(value_, w));\
	}\
	static CONCAT2(datatype, 4) operator * (CONCAT2(datatype, 4) value0, datatype value1){\
		return CONCAT2(datatype, 4)(value0.CONCAT2(value_, x) * value1, value0.CONCAT2(value_, y) * value1, value0.CONCAT2(value_, z) * value1, value0.CONCAT2(value_, w) * value1);\
	}\
	static CONCAT2(datatype, 4) operator / (CONCAT2(datatype, 4) value0, datatype value1){\
		if(value1 == 0){\
			throw gcnew System::DivideByZeroException();\
		}\
		return CONCAT2(datatype, 4)(value0.CONCAT2(value_, x) / value1, value0.CONCAT2(value_, y) / value1, value0.CONCAT2(value_, z) / value1, value0.CONCAT2(value_, w) / value1);\
	}\
	static bool operator != (CONCAT2(datatype, 4) value0, CONCAT2(datatype, 4) value1){\
		return value0.CONCAT2(value_, x) != value1.CONCAT2(value_, x) || value0.CONCAT2(value_, y) != value1.CONCAT2(value_, y) || value0.CONCAT2(value_, z) != value1.CONCAT2(value_, z) || value0.CONCAT2(value_, w) != value1.CONCAT2(value_, w);\
	}\
	static bool operator == (CONCAT2(datatype, 4) value0, CONCAT2(datatype, 4) value1){\
		return value0.CONCAT2(value_, x) == value1.CONCAT2(value_, x) && value0.CONCAT2(value_, y) == value1.CONCAT2(value_, y) && value0.CONCAT2(value_, z) == value1.CONCAT2(value_, z) && value0.CONCAT2(value_, w) == value1.CONCAT2(value_, w);\
	}\
	static bool operator != (CONCAT2(datatype, 4) value0, datatype value1){\
		return value0.CONCAT2(value_, x) != value1 || value0.CONCAT2(value_, y) != value1 || value0.CONCAT2(value_, z) != value1 || value0.CONCAT2(value_, w) != value1;\
	}\
	static bool operator == (CONCAT2(datatype, 4) value0, datatype value1){\
		return value0.CONCAT2(value_, x) == value1 && value0.CONCAT2(value_, y) == value1 && value0.CONCAT2(value_, z) == value1 && value0.CONCAT2(value_, w) == value1;\
	}\
	CONCAT2(datatype, 4)(datatype x, datatype y, datatype z, datatype w){\
		this->CONCAT2(value_, x) = x;\
		this->CONCAT2(value_, y) = y;\
		this->CONCAT2(value_, z) = z;\
		this->CONCAT2(value_, w) = w;\
	}\
	CONCAT2(datatype, 4)(datatype x, CONCAT2(datatype, 3) value){\
		this->CONCAT2(value_, x) = x;\
		this->CONCAT2(value_, y) = value.CONCAT2(value_, x);\
		this->CONCAT2(value_, z) = value.CONCAT2(value_, y);\
		this->CONCAT2(value_, w) = value.CONCAT2(value_, z);\
	}\
	CONCAT2(datatype, 4)(CONCAT2(datatype, 3) value, datatype w){\
		this->CONCAT2(value_, x) = value.CONCAT2(value_, x);\
		this->CONCAT2(value_, y) = value.CONCAT2(value_, y);\
		this->CONCAT2(value_, z) = value.CONCAT2(value_, z);\
		this->CONCAT2(value_, w) = w;\
	}\
	CONCAT2(datatype, 4)(CONCAT2(datatype, 2) value, datatype z, datatype w){\
		this->CONCAT2(value_, x) = value.CONCAT2(value_, x);\
		this->CONCAT2(value_, y) = value.CONCAT2(value_, y);\
		this->CONCAT2(value_, z) = z;\
		this->CONCAT2(value_, w) = w;\
	}\
	CONCAT2(datatype, 4)(datatype x, CONCAT2(datatype, 2) value, datatype w){\
		this->CONCAT2(value_, x) = x;\
		this->CONCAT2(value_, y) = value.CONCAT2(value_, x);\
		this->CONCAT2(value_, z) = value.CONCAT2(value_, y);\
		this->CONCAT2(value_, w) = w;\
	}\
	CONCAT2(datatype, 4)(datatype x, datatype y, CONCAT2(datatype, 2) value){\
		this->CONCAT2(value_, x) = x;\
		this->CONCAT2(value_, y) = y;\
		this->CONCAT2(value_, z) = value.CONCAT2(value_, x);\
		this->CONCAT2(value_, w) = value.CONCAT2(value_, y);\
	}\
	CONCAT2(datatype, 4)(CONCAT2(datatype, 2) value0, CONCAT2(datatype, 2) value1){\
		this->CONCAT2(value_, x) = value0.CONCAT2(value_, x);\
		this->CONCAT2(value_, y) = value0.CONCAT2(value_, y);\
		this->CONCAT2(value_, z) = value1.CONCAT2(value_, x);\
		this->CONCAT2(value_, w) = value1.CONCAT2(value_, y);\
	}\
	CONCAT2(datatype, 4)(datatype value){\
		this->CONCAT2(value_, x) = value;\
		this->CONCAT2(value_, y) = value;\
		this->CONCAT2(value_, z) = value;\
		this->CONCAT2(value_, w) = value;\
	}\
};



#define DATATYPEVECTOR(datatype)\
DATATYPE2(datatype)\
DATATYPE3(datatype)\
DATATYPE4(datatype)



namespace fDatatypes {


	DATATYPEVECTOR(int)
	DATATYPEVECTOR(float)
	DATATYPEVECTOR(long)
	DATATYPEVECTOR(short)
	DATATYPEVECTOR(double)

}