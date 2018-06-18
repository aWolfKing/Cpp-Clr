#pragma once

using namespace System;

#define CONCAT2(s0, s1) s0##s1
#define CONCAT3(s0, s1, s2) s0##s1##s2
#define CONCAT4(s0, s1, s2, s3) s0##s1##s2##s3



#define NAMEDVALUEPROPERTY1(name, datatype, valueID)property datatype valueID{\
		datatype get(){\
			return this->CONCAT2(value_, valueID);\
		}\
		void set(datatype value){\
			this->CONCAT2(value_, valueID) = value;\
		}\
	}\

#define NAMEDVALUEPROPERTY2(name, datatype, valueID0, valueID1)property CONCAT2(name, 2) CONCAT2(valueID0, valueID1){\
		CONCAT2(name, 2) get(){\
			return CONCAT2(name, 2)(this->CONCAT2(value_, valueID0), this->CONCAT2(value_, valueID1));\
		}\
		void set(CONCAT2(name, 2) value){\
			this->CONCAT2(value_, valueID0) = value.CONCAT2(value_, x);\
			this->CONCAT2(value_, valueID1) = value.CONCAT2(value_, y);\
		}\
	}\

#define NAMEDVALUEPROPERTY3(name, datatype, valueID0, valueID1, valueID2)property CONCAT2(name, 3) CONCAT3(valueID0, valueID1, valueID2) {\
		CONCAT2(name, 3) get(){\
			return CONCAT2(name, 3)(this->CONCAT2(value_, valueID0), this->CONCAT2(value_, valueID1), this->CONCAT2(value_, valueID2));\
		}\
		void set(CONCAT2(name, 3) value){\
			this->CONCAT2(value_, valueID0) = value.CONCAT2(value_, x);\
			this->CONCAT2(value_, valueID1) = value.CONCAT2(value_, y);\
			this->CONCAT2(value_, valueID2) = value.CONCAT2(value_, z);\
		}\
	}\

#define NAMEDVALUEPROPERTY4(name, datatype, valueID0, valueID1, valueID2, valueID3)property CONCAT2(name, 4) CONCAT4(valueID0, valueID1, valueID2, valueID3) {\
		CONCAT2(name, 4) get(){\
			return CONCAT2(name, 4)(this->CONCAT2(value_, valueID0), this->CONCAT2(value_, valueID1), this->CONCAT2(value_, valueID2), this->CONCAT2(value_, valueID3));\
		}\
		void set(CONCAT2(name, 4) value){\
			this->CONCAT2(value_, valueID0) = value.CONCAT2(value_, x);\
			this->CONCAT2(value_, valueID1) = value.CONCAT2(value_, y);\
			this->CONCAT2(value_, valueID2) = value.CONCAT2(value_, z);\
			this->CONCAT2(value_, valueID3) = value.CONCAT2(value_, w);\
		}\
	}\



#define NAMEDDATATYPE2(name, datatype) public value struct CONCAT2(name, 2) {\
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
	NAMEDVALUEPROPERTY1(name, datatype, x)\
	NAMEDVALUEPROPERTY1(name, datatype, y)\
	NAMEDVALUEPROPERTY2(name, datatype, x, x)\
	NAMEDVALUEPROPERTY2(name, datatype, x, y)\
	NAMEDVALUEPROPERTY2(name, datatype, y, x)\
	NAMEDVALUEPROPERTY2(name, datatype, y, y)\
	static operator CONCAT2(name, 2)(datatype value){\
		return CONCAT2(name, 2)(value, value);\
	}\
	static CONCAT2(name, 2) operator + (CONCAT2(name, 2) value0, datatype value1){\
		return CONCAT2(name, 2)(value0.CONCAT2(value_, x) + value1, value0.CONCAT2(value_, y) + value1);\
	}\
	static CONCAT2(name, 2) operator + (CONCAT2(name, 2) value0, CONCAT2(name, 2) value1){\
		return CONCAT2(name, 2)(value0.CONCAT2(value_, x) + value1.CONCAT2(value_, x), value0.CONCAT2(value_, y) + value1.CONCAT2(value_, y));\
	}\
	static CONCAT2(name, 2) operator - (CONCAT2(name, 2) value0, datatype value1){\
		return CONCAT2(name, 2)(value0.CONCAT2(value_, x) - value1, value0.CONCAT2(value_, y) - value1);\
	}\
	static CONCAT2(name, 2) operator - (CONCAT2(name, 2) value0, CONCAT2(name, 2) value1){\
		return CONCAT2(name, 2)(value0.CONCAT2(value_, x) - value1.CONCAT2(value_, x), value0.CONCAT2(value_, y) - value1.CONCAT2(value_, y));\
	}\
	static CONCAT2(name, 2) operator - (CONCAT2(name, 2) value){\
		return CONCAT2(name, 2)(-value.CONCAT2(value_, x), -value.CONCAT2(value_, y));\
	}\
	static CONCAT2(name, 2) operator * (CONCAT2(name, 2) value0, datatype value1){\
		return CONCAT2(name, 2)(value0.CONCAT2(value_, x) * value1, value0.CONCAT2(value_, y) * value1);\
	}\
	static CONCAT2(name, 2) operator / (CONCAT2(name, 2) value0, datatype value1){\
		if(value1 == 0){\
			throw gcnew System::DivideByZeroException();\
		}\
		return CONCAT2(name, 2)(value0.CONCAT2(value_, x) / value1, value0.CONCAT2(value_, y) / value1);\
	}\
	static bool operator != (CONCAT2(name, 2) value0, CONCAT2(name, 2) value1){\
		return value0.CONCAT2(value_, x) != value1.CONCAT2(value_, x) || value0.CONCAT2(value_, y) != value1.CONCAT2(value_, y);\
	}\
	static bool operator == (CONCAT2(name, 2) value0, CONCAT2(name, 2) value1){\
		return value0.CONCAT2(value_, x) == value1.CONCAT2(value_, x) && value0.CONCAT2(value_, y) == value1.CONCAT2(value_, y);\
	}\
	static bool operator != (CONCAT2(name, 2) value0, datatype value1){\
		return value0.CONCAT2(value_, x) != value1 || value0.CONCAT2(value_, y) != value1;\
	}\
	static bool operator == (CONCAT2(name, 2) value0, datatype value1){\
		return value0.CONCAT2(value_, x) == value1 && value0.CONCAT2(value_, y) == value1;\
	}\
	CONCAT2(name, 2)(datatype x, datatype y){\
		this->CONCAT2(value_, x) = x;\
		this->CONCAT2(value_, y) = y;\
	}\
	CONCAT2(name, 2)(datatype value){\
		this->CONCAT2(value_, x) = value;\
		this->CONCAT2(value_, y) = value;\
	}\
};



#define NAMEDDATATYPE3(name, datatype) public value struct CONCAT2(name, 3) {\
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
	NAMEDVALUEPROPERTY1(name, datatype, x)\
	NAMEDVALUEPROPERTY1(name, datatype, y)\
	NAMEDVALUEPROPERTY1(name, datatype, z)\
	NAMEDVALUEPROPERTY2(name, datatype, x, x)\
	NAMEDVALUEPROPERTY2(name, datatype, x, y)\
	NAMEDVALUEPROPERTY2(name, datatype, x, z)\
	NAMEDVALUEPROPERTY2(name, datatype, y, x)\
	NAMEDVALUEPROPERTY2(name, datatype, y, y)\
	NAMEDVALUEPROPERTY2(name, datatype, y, z)\
	NAMEDVALUEPROPERTY2(name, datatype, z, x)\
	NAMEDVALUEPROPERTY2(name, datatype, z, y)\
	NAMEDVALUEPROPERTY2(name, datatype, z, z)\
	NAMEDVALUEPROPERTY3(name, datatype, x, x, x)\
	NAMEDVALUEPROPERTY3(name, datatype, x, x, y)\
	NAMEDVALUEPROPERTY3(name, datatype, x, x, z)\
	NAMEDVALUEPROPERTY3(name, datatype, x, y, x)\
	NAMEDVALUEPROPERTY3(name, datatype, x, y, y)\
	NAMEDVALUEPROPERTY3(name, datatype, x, y, z)\
	NAMEDVALUEPROPERTY3(name, datatype, x, z, x)\
	NAMEDVALUEPROPERTY3(name, datatype, x, z, y)\
	NAMEDVALUEPROPERTY3(name, datatype, x, z, z)\
	NAMEDVALUEPROPERTY3(name, datatype, y, x, x)\
	NAMEDVALUEPROPERTY3(name, datatype, y, x, y)\
	NAMEDVALUEPROPERTY3(name, datatype, y, x, z)\
	NAMEDVALUEPROPERTY3(name, datatype, y, y, x)\
	NAMEDVALUEPROPERTY3(name, datatype, y, y, y)\
	NAMEDVALUEPROPERTY3(name, datatype, y, y, z)\
	NAMEDVALUEPROPERTY3(name, datatype, y, z, x)\
	NAMEDVALUEPROPERTY3(name, datatype, y, z, y)\
	NAMEDVALUEPROPERTY3(name, datatype, y, z, z)\
	NAMEDVALUEPROPERTY3(name, datatype, z, x, x)\
	NAMEDVALUEPROPERTY3(name, datatype, z, x, y)\
	NAMEDVALUEPROPERTY3(name, datatype, z, x, z)\
	NAMEDVALUEPROPERTY3(name, datatype, z, y, x)\
	NAMEDVALUEPROPERTY3(name, datatype, z, y, y)\
	NAMEDVALUEPROPERTY3(name, datatype, z, y, z)\
	NAMEDVALUEPROPERTY3(name, datatype, z, z, x)\
	NAMEDVALUEPROPERTY3(name, datatype, z, z, y)\
	NAMEDVALUEPROPERTY3(name, datatype, z, z, z)\
	static operator CONCAT2(name, 3)(datatype value){\
		return CONCAT2(name, 3)(value, value, value);\
	}\
	static CONCAT2(name, 3) operator + (CONCAT2(name, 3) value0, datatype value1){\
		return CONCAT2(name, 3)(value0.CONCAT2(value_, x) + value1, value0.CONCAT2(value_, y) + value1, value0.CONCAT2(value_, z) + value1);\
	}\
	static CONCAT2(name, 3) operator + (CONCAT2(name, 3) value0, CONCAT2(name, 3) value1){\
		return CONCAT2(name, 3)(value0.CONCAT2(value_, x) + value1.CONCAT2(value_, x), value0.CONCAT2(value_, y) + value1.CONCAT2(value_, y), value0.CONCAT2(value_, z) + value1.CONCAT2(value_, z));\
	}\
	static CONCAT2(name, 3) operator - (CONCAT2(name, 3) value0, datatype value1){\
		return CONCAT2(name, 3)(value0.CONCAT2(value_, x) - value1, value0.CONCAT2(value_, y) - value1, value0.CONCAT2(value_, z) - value1);\
	}\
	static CONCAT2(name, 3) operator - (CONCAT2(name, 3) value0, CONCAT2(name, 3) value1){\
		return CONCAT2(name, 3)(value0.CONCAT2(value_, x) - value1.CONCAT2(value_, x), value0.CONCAT2(value_, y) - value1.CONCAT2(value_, y), value0.CONCAT2(value_, z) - value1.CONCAT2(value_, z));\
	}\
	static CONCAT2(name, 3) operator - (CONCAT2(name, 3) value){\
		return CONCAT2(name, 3)(-value.CONCAT2(value_, x), -value.CONCAT2(value_, y), -value.CONCAT2(value_, z));\
	}\
	static CONCAT2(name, 3) operator * (CONCAT2(name, 3) value0, datatype value1){\
		return CONCAT2(name, 3)(value0.CONCAT2(value_, x) * value1, value0.CONCAT2(value_, y) * value1, value0.CONCAT2(value_, z) * value1);\
	}\
	static CONCAT2(name, 3) operator / (CONCAT2(name, 3) value0, datatype value1){\
		if(value1 == 0){\
			throw gcnew System::DivideByZeroException();\
		}\
		return CONCAT2(name, 3)(value0.CONCAT2(value_, x) / value1, value0.CONCAT2(value_, y) / value1, value0.CONCAT2(value_, z) / value1);\
	}\
	static bool operator != (CONCAT2(name, 3) value0, CONCAT2(name, 3) value1){\
		return value0.CONCAT2(value_, x) != value1.CONCAT2(value_, x) || value0.CONCAT2(value_, y) != value1.CONCAT2(value_, y) || value0.CONCAT2(value_, z) != value1.CONCAT2(value_, z);\
	}\
	static bool operator == (CONCAT2(name, 3) value0, CONCAT2(name, 3) value1){\
		return value0.CONCAT2(value_, x) == value1.CONCAT2(value_, x) && value0.CONCAT2(value_, y) == value1.CONCAT2(value_, y) && value0.CONCAT2(value_, z) == value1.CONCAT2(value_, z);\
	}\
	static bool operator != (CONCAT2(name, 3) value0, datatype value1){\
		return value0.CONCAT2(value_, x) != value1 || value0.CONCAT2(value_, y) != value1 || value0.CONCAT2(value_, z) != value1;\
	}\
	static bool operator == (CONCAT2(name, 3) value0, datatype value1){\
		return value0.CONCAT2(value_, x) == value1 && value0.CONCAT2(value_, y) == value1 && value0.CONCAT2(value_, z) == value1;\
	}\
	CONCAT2(name, 3)(datatype x, datatype y, datatype z){\
		this->CONCAT2(value_, x) = x;\
		this->CONCAT2(value_, y) = y;\
		this->CONCAT2(value_, z) = z;\
	}\
	CONCAT2(name, 3)(datatype x, CONCAT2(name, 2) value){\
		this->CONCAT2(value_, x) = x;\
		this->CONCAT2(value_, y) = value.CONCAT2(value_, x);\
		this->CONCAT2(value_, z) = value.CONCAT2(value_, y);\
	}\
	CONCAT2(name, 3)(CONCAT2(name, 2) value, datatype z){\
		this->CONCAT2(value_, x) = value.CONCAT2(value_, x);\
		this->CONCAT2(value_, y) = value.CONCAT2(value_, y);\
		this->CONCAT2(value_, z) = z;\
	}\
	CONCAT2(name, 3)(datatype value){\
		this->CONCAT2(value_, x) = value;\
		this->CONCAT2(value_, y) = value;\
		this->CONCAT2(value_, z) = value;\
	}\
};



#define NAMEDDATATYPE4(name, datatype) public value struct CONCAT2(name, 4) {\
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
	NAMEDVALUEPROPERTY1(name, datatype, x)\
	NAMEDVALUEPROPERTY1(name, datatype, y)\
	NAMEDVALUEPROPERTY1(name, datatype, z)\
	NAMEDVALUEPROPERTY1(name, datatype, w)\
	NAMEDVALUEPROPERTY2(name, datatype, x, x)\
	NAMEDVALUEPROPERTY2(name, datatype, x, y)\
	NAMEDVALUEPROPERTY2(name, datatype, x, z)\
	NAMEDVALUEPROPERTY2(name, datatype, x, w)\
	NAMEDVALUEPROPERTY2(name, datatype, y, x)\
	NAMEDVALUEPROPERTY2(name, datatype, y, y)\
	NAMEDVALUEPROPERTY2(name, datatype, y, z)\
	NAMEDVALUEPROPERTY2(name, datatype, y, w)\
	NAMEDVALUEPROPERTY2(name, datatype, z, x)\
	NAMEDVALUEPROPERTY2(name, datatype, z, y)\
	NAMEDVALUEPROPERTY2(name, datatype, z, z)\
	NAMEDVALUEPROPERTY2(name, datatype, z, w)\
	NAMEDVALUEPROPERTY2(name, datatype, w, x)\
	NAMEDVALUEPROPERTY2(name, datatype, w, y)\
	NAMEDVALUEPROPERTY2(name, datatype, w, z)\
	NAMEDVALUEPROPERTY2(name, datatype, w, w)\
	NAMEDVALUEPROPERTY3(name, datatype, x, x, x)\
	NAMEDVALUEPROPERTY3(name, datatype, x, x, y)\
	NAMEDVALUEPROPERTY3(name, datatype, x, x, z)\
	NAMEDVALUEPROPERTY3(name, datatype, x, x, w)\
	NAMEDVALUEPROPERTY3(name, datatype, x, y, x)\
	NAMEDVALUEPROPERTY3(name, datatype, x, y, y)\
	NAMEDVALUEPROPERTY3(name, datatype, x, y, z)\
	NAMEDVALUEPROPERTY3(name, datatype, x, y, w)\
	NAMEDVALUEPROPERTY3(name, datatype, x, z, x)\
	NAMEDVALUEPROPERTY3(name, datatype, x, z, y)\
	NAMEDVALUEPROPERTY3(name, datatype, x, z, z)\
	NAMEDVALUEPROPERTY3(name, datatype, x, z, w)\
	NAMEDVALUEPROPERTY3(name, datatype, x, w, x)\
	NAMEDVALUEPROPERTY3(name, datatype, x, w, y)\
	NAMEDVALUEPROPERTY3(name, datatype, x, w, z)\
	NAMEDVALUEPROPERTY3(name, datatype, x, w, w)\
	NAMEDVALUEPROPERTY3(name, datatype, y, x, x)\
	NAMEDVALUEPROPERTY3(name, datatype, y, x, y)\
	NAMEDVALUEPROPERTY3(name, datatype, y, x, z)\
	NAMEDVALUEPROPERTY3(name, datatype, y, x, w)\
	NAMEDVALUEPROPERTY3(name, datatype, y, y, x)\
	NAMEDVALUEPROPERTY3(name, datatype, y, y, y)\
	NAMEDVALUEPROPERTY3(name, datatype, y, y, z)\
	NAMEDVALUEPROPERTY3(name, datatype, y, y, w)\
	NAMEDVALUEPROPERTY3(name, datatype, y, z, x)\
	NAMEDVALUEPROPERTY3(name, datatype, y, z, y)\
	NAMEDVALUEPROPERTY3(name, datatype, y, z, z)\
	NAMEDVALUEPROPERTY3(name, datatype, y, z, w)\
	NAMEDVALUEPROPERTY3(name, datatype, y, w, x)\
	NAMEDVALUEPROPERTY3(name, datatype, y, w, y)\
	NAMEDVALUEPROPERTY3(name, datatype, y, w, z)\
	NAMEDVALUEPROPERTY3(name, datatype, y, w, w)\
	NAMEDVALUEPROPERTY3(name, datatype, z, x, x)\
	NAMEDVALUEPROPERTY3(name, datatype, z, x, y)\
	NAMEDVALUEPROPERTY3(name, datatype, z, x, z)\
	NAMEDVALUEPROPERTY3(name, datatype, z, x, w)\
	NAMEDVALUEPROPERTY3(name, datatype, z, y, x)\
	NAMEDVALUEPROPERTY3(name, datatype, z, y, y)\
	NAMEDVALUEPROPERTY3(name, datatype, z, y, z)\
	NAMEDVALUEPROPERTY3(name, datatype, z, y, w)\
	NAMEDVALUEPROPERTY3(name, datatype, z, z, x)\
	NAMEDVALUEPROPERTY3(name, datatype, z, z, y)\
	NAMEDVALUEPROPERTY3(name, datatype, z, z, z)\
	NAMEDVALUEPROPERTY3(name, datatype, z, z, w)\
	NAMEDVALUEPROPERTY3(name, datatype, z, w, x)\
	NAMEDVALUEPROPERTY3(name, datatype, z, w, y)\
	NAMEDVALUEPROPERTY3(name, datatype, z, w, z)\
	NAMEDVALUEPROPERTY3(name, datatype, z, w, w)\
	NAMEDVALUEPROPERTY3(name, datatype, w, x, x)\
	NAMEDVALUEPROPERTY3(name, datatype, w, x, y)\
	NAMEDVALUEPROPERTY3(name, datatype, w, x, z)\
	NAMEDVALUEPROPERTY3(name, datatype, w, x, w)\
	NAMEDVALUEPROPERTY3(name, datatype, w, y, x)\
	NAMEDVALUEPROPERTY3(name, datatype, w, y, y)\
	NAMEDVALUEPROPERTY3(name, datatype, w, y, z)\
	NAMEDVALUEPROPERTY3(name, datatype, w, y, w)\
	NAMEDVALUEPROPERTY3(name, datatype, w, z, x)\
	NAMEDVALUEPROPERTY3(name, datatype, w, z, y)\
	NAMEDVALUEPROPERTY3(name, datatype, w, z, z)\
	NAMEDVALUEPROPERTY3(name, datatype, w, z, w)\
	NAMEDVALUEPROPERTY3(name, datatype, w, w, x)\
	NAMEDVALUEPROPERTY3(name, datatype, w, w, y)\
	NAMEDVALUEPROPERTY3(name, datatype, w, w, z)\
	NAMEDVALUEPROPERTY3(name, datatype, w, w, w)\
	NAMEDVALUEPROPERTY4(name, datatype, x, x, x, x)\
	NAMEDVALUEPROPERTY4(name, datatype, x, x, x, y)\
	NAMEDVALUEPROPERTY4(name, datatype, x, x, x, z)\
	NAMEDVALUEPROPERTY4(name, datatype, x, x, x, w)\
	NAMEDVALUEPROPERTY4(name, datatype, x, x, y, x)\
	NAMEDVALUEPROPERTY4(name, datatype, x, x, y, y)\
	NAMEDVALUEPROPERTY4(name, datatype, x, x, y, z)\
	NAMEDVALUEPROPERTY4(name, datatype, x, x, y, w)\
	NAMEDVALUEPROPERTY4(name, datatype, x, x, z, x)\
	NAMEDVALUEPROPERTY4(name, datatype, x, x, z, y)\
	NAMEDVALUEPROPERTY4(name, datatype, x, x, z, z)\
	NAMEDVALUEPROPERTY4(name, datatype, x, x, z, w)\
	NAMEDVALUEPROPERTY4(name, datatype, x, x, w, x)\
	NAMEDVALUEPROPERTY4(name, datatype, x, x, w, y)\
	NAMEDVALUEPROPERTY4(name, datatype, x, x, w, z)\
	NAMEDVALUEPROPERTY4(name, datatype, x, x, w, w)\
	NAMEDVALUEPROPERTY4(name, datatype, x, y, x, x)\
	NAMEDVALUEPROPERTY4(name, datatype, x, y, x, y)\
	NAMEDVALUEPROPERTY4(name, datatype, x, y, x, z)\
	NAMEDVALUEPROPERTY4(name, datatype, x, y, x, w)\
	NAMEDVALUEPROPERTY4(name, datatype, x, y, y, x)\
	NAMEDVALUEPROPERTY4(name, datatype, x, y, y, y)\
	NAMEDVALUEPROPERTY4(name, datatype, x, y, y, z)\
	NAMEDVALUEPROPERTY4(name, datatype, x, y, y, w)\
	NAMEDVALUEPROPERTY4(name, datatype, x, y, z, x)\
	NAMEDVALUEPROPERTY4(name, datatype, x, y, z, y)\
	NAMEDVALUEPROPERTY4(name, datatype, x, y, z, z)\
	NAMEDVALUEPROPERTY4(name, datatype, x, y, z, w)\
	NAMEDVALUEPROPERTY4(name, datatype, x, y, w, x)\
	NAMEDVALUEPROPERTY4(name, datatype, x, y, w, y)\
	NAMEDVALUEPROPERTY4(name, datatype, x, y, w, z)\
	NAMEDVALUEPROPERTY4(name, datatype, x, y, w, w)\
	NAMEDVALUEPROPERTY4(name, datatype, x, z, x, x)\
	NAMEDVALUEPROPERTY4(name, datatype, x, z, x, y)\
	NAMEDVALUEPROPERTY4(name, datatype, x, z, x, z)\
	NAMEDVALUEPROPERTY4(name, datatype, x, z, x, w)\
	NAMEDVALUEPROPERTY4(name, datatype, x, z, y, x)\
	NAMEDVALUEPROPERTY4(name, datatype, x, z, y, y)\
	NAMEDVALUEPROPERTY4(name, datatype, x, z, y, z)\
	NAMEDVALUEPROPERTY4(name, datatype, x, z, y, w)\
	NAMEDVALUEPROPERTY4(name, datatype, x, z, z, x)\
	NAMEDVALUEPROPERTY4(name, datatype, x, z, z, y)\
	NAMEDVALUEPROPERTY4(name, datatype, x, z, z, z)\
	NAMEDVALUEPROPERTY4(name, datatype, x, z, z, w)\
	NAMEDVALUEPROPERTY4(name, datatype, x, z, w, x)\
	NAMEDVALUEPROPERTY4(name, datatype, x, z, w, y)\
	NAMEDVALUEPROPERTY4(name, datatype, x, z, w, z)\
	NAMEDVALUEPROPERTY4(name, datatype, x, z, w, w)\
	NAMEDVALUEPROPERTY4(name, datatype, x, w, x, x)\
	NAMEDVALUEPROPERTY4(name, datatype, x, w, x, y)\
	NAMEDVALUEPROPERTY4(name, datatype, x, w, x, z)\
	NAMEDVALUEPROPERTY4(name, datatype, x, w, x, w)\
	NAMEDVALUEPROPERTY4(name, datatype, x, w, y, x)\
	NAMEDVALUEPROPERTY4(name, datatype, x, w, y, y)\
	NAMEDVALUEPROPERTY4(name, datatype, x, w, y, z)\
	NAMEDVALUEPROPERTY4(name, datatype, x, w, y, w)\
	NAMEDVALUEPROPERTY4(name, datatype, x, w, z, x)\
	NAMEDVALUEPROPERTY4(name, datatype, x, w, z, y)\
	NAMEDVALUEPROPERTY4(name, datatype, x, w, z, z)\
	NAMEDVALUEPROPERTY4(name, datatype, x, w, z, w)\
	NAMEDVALUEPROPERTY4(name, datatype, x, w, w, x)\
	NAMEDVALUEPROPERTY4(name, datatype, x, w, w, y)\
	NAMEDVALUEPROPERTY4(name, datatype, x, w, w, z)\
	NAMEDVALUEPROPERTY4(name, datatype, x, w, w, w)\
	NAMEDVALUEPROPERTY4(name, datatype, y, x, x, x)\
	NAMEDVALUEPROPERTY4(name, datatype, y, x, x, y)\
	NAMEDVALUEPROPERTY4(name, datatype, y, x, x, z)\
	NAMEDVALUEPROPERTY4(name, datatype, y, x, x, w)\
	NAMEDVALUEPROPERTY4(name, datatype, y, x, y, x)\
	NAMEDVALUEPROPERTY4(name, datatype, y, x, y, y)\
	NAMEDVALUEPROPERTY4(name, datatype, y, x, y, z)\
	NAMEDVALUEPROPERTY4(name, datatype, y, x, y, w)\
	NAMEDVALUEPROPERTY4(name, datatype, y, x, z, x)\
	NAMEDVALUEPROPERTY4(name, datatype, y, x, z, y)\
	NAMEDVALUEPROPERTY4(name, datatype, y, x, z, z)\
	NAMEDVALUEPROPERTY4(name, datatype, y, x, z, w)\
	NAMEDVALUEPROPERTY4(name, datatype, y, x, w, x)\
	NAMEDVALUEPROPERTY4(name, datatype, y, x, w, y)\
	NAMEDVALUEPROPERTY4(name, datatype, y, x, w, z)\
	NAMEDVALUEPROPERTY4(name, datatype, y, x, w, w)\
	NAMEDVALUEPROPERTY4(name, datatype, y, y, x, x)\
	NAMEDVALUEPROPERTY4(name, datatype, y, y, x, y)\
	NAMEDVALUEPROPERTY4(name, datatype, y, y, x, z)\
	NAMEDVALUEPROPERTY4(name, datatype, y, y, x, w)\
	NAMEDVALUEPROPERTY4(name, datatype, y, y, y, x)\
	NAMEDVALUEPROPERTY4(name, datatype, y, y, y, y)\
	NAMEDVALUEPROPERTY4(name, datatype, y, y, y, z)\
	NAMEDVALUEPROPERTY4(name, datatype, y, y, y, w)\
	NAMEDVALUEPROPERTY4(name, datatype, y, y, z, x)\
	NAMEDVALUEPROPERTY4(name, datatype, y, y, z, y)\
	NAMEDVALUEPROPERTY4(name, datatype, y, y, z, z)\
	NAMEDVALUEPROPERTY4(name, datatype, y, y, z, w)\
	NAMEDVALUEPROPERTY4(name, datatype, y, y, w, x)\
	NAMEDVALUEPROPERTY4(name, datatype, y, y, w, y)\
	NAMEDVALUEPROPERTY4(name, datatype, y, y, w, z)\
	NAMEDVALUEPROPERTY4(name, datatype, y, y, w, w)\
	NAMEDVALUEPROPERTY4(name, datatype, y, z, x, x)\
	NAMEDVALUEPROPERTY4(name, datatype, y, z, x, y)\
	NAMEDVALUEPROPERTY4(name, datatype, y, z, x, z)\
	NAMEDVALUEPROPERTY4(name, datatype, y, z, x, w)\
	NAMEDVALUEPROPERTY4(name, datatype, y, z, y, x)\
	NAMEDVALUEPROPERTY4(name, datatype, y, z, y, y)\
	NAMEDVALUEPROPERTY4(name, datatype, y, z, y, z)\
	NAMEDVALUEPROPERTY4(name, datatype, y, z, y, w)\
	NAMEDVALUEPROPERTY4(name, datatype, y, z, z, x)\
	NAMEDVALUEPROPERTY4(name, datatype, y, z, z, y)\
	NAMEDVALUEPROPERTY4(name, datatype, y, z, z, z)\
	NAMEDVALUEPROPERTY4(name, datatype, y, z, z, w)\
	NAMEDVALUEPROPERTY4(name, datatype, y, z, w, x)\
	NAMEDVALUEPROPERTY4(name, datatype, y, z, w, y)\
	NAMEDVALUEPROPERTY4(name, datatype, y, z, w, z)\
	NAMEDVALUEPROPERTY4(name, datatype, y, z, w, w)\
	NAMEDVALUEPROPERTY4(name, datatype, y, w, x, x)\
	NAMEDVALUEPROPERTY4(name, datatype, y, w, x, y)\
	NAMEDVALUEPROPERTY4(name, datatype, y, w, x, z)\
	NAMEDVALUEPROPERTY4(name, datatype, y, w, x, w)\
	NAMEDVALUEPROPERTY4(name, datatype, y, w, y, x)\
	NAMEDVALUEPROPERTY4(name, datatype, y, w, y, y)\
	NAMEDVALUEPROPERTY4(name, datatype, y, w, y, z)\
	NAMEDVALUEPROPERTY4(name, datatype, y, w, y, w)\
	NAMEDVALUEPROPERTY4(name, datatype, y, w, z, x)\
	NAMEDVALUEPROPERTY4(name, datatype, y, w, z, y)\
	NAMEDVALUEPROPERTY4(name, datatype, y, w, z, z)\
	NAMEDVALUEPROPERTY4(name, datatype, y, w, z, w)\
	NAMEDVALUEPROPERTY4(name, datatype, y, w, w, x)\
	NAMEDVALUEPROPERTY4(name, datatype, y, w, w, y)\
	NAMEDVALUEPROPERTY4(name, datatype, y, w, w, z)\
	NAMEDVALUEPROPERTY4(name, datatype, y, w, w, w)\
	NAMEDVALUEPROPERTY4(name, datatype, z, x, x, x)\
	NAMEDVALUEPROPERTY4(name, datatype, z, x, x, y)\
	NAMEDVALUEPROPERTY4(name, datatype, z, x, x, z)\
	NAMEDVALUEPROPERTY4(name, datatype, z, x, x, w)\
	NAMEDVALUEPROPERTY4(name, datatype, z, x, y, x)\
	NAMEDVALUEPROPERTY4(name, datatype, z, x, y, y)\
	NAMEDVALUEPROPERTY4(name, datatype, z, x, y, z)\
	NAMEDVALUEPROPERTY4(name, datatype, z, x, y, w)\
	NAMEDVALUEPROPERTY4(name, datatype, z, x, z, x)\
	NAMEDVALUEPROPERTY4(name, datatype, z, x, z, y)\
	NAMEDVALUEPROPERTY4(name, datatype, z, x, z, z)\
	NAMEDVALUEPROPERTY4(name, datatype, z, x, z, w)\
	NAMEDVALUEPROPERTY4(name, datatype, z, x, w, x)\
	NAMEDVALUEPROPERTY4(name, datatype, z, x, w, y)\
	NAMEDVALUEPROPERTY4(name, datatype, z, x, w, z)\
	NAMEDVALUEPROPERTY4(name, datatype, z, x, w, w)\
	NAMEDVALUEPROPERTY4(name, datatype, z, y, x, x)\
	NAMEDVALUEPROPERTY4(name, datatype, z, y, x, y)\
	NAMEDVALUEPROPERTY4(name, datatype, z, y, x, z)\
	NAMEDVALUEPROPERTY4(name, datatype, z, y, x, w)\
	NAMEDVALUEPROPERTY4(name, datatype, z, y, y, x)\
	NAMEDVALUEPROPERTY4(name, datatype, z, y, y, y)\
	NAMEDVALUEPROPERTY4(name, datatype, z, y, y, z)\
	NAMEDVALUEPROPERTY4(name, datatype, z, y, y, w)\
	NAMEDVALUEPROPERTY4(name, datatype, z, y, z, x)\
	NAMEDVALUEPROPERTY4(name, datatype, z, y, z, y)\
	NAMEDVALUEPROPERTY4(name, datatype, z, y, z, z)\
	NAMEDVALUEPROPERTY4(name, datatype, z, y, z, w)\
	NAMEDVALUEPROPERTY4(name, datatype, z, y, w, x)\
	NAMEDVALUEPROPERTY4(name, datatype, z, y, w, y)\
	NAMEDVALUEPROPERTY4(name, datatype, z, y, w, z)\
	NAMEDVALUEPROPERTY4(name, datatype, z, y, w, w)\
	NAMEDVALUEPROPERTY4(name, datatype, z, z, x, x)\
	NAMEDVALUEPROPERTY4(name, datatype, z, z, x, y)\
	NAMEDVALUEPROPERTY4(name, datatype, z, z, x, z)\
	NAMEDVALUEPROPERTY4(name, datatype, z, z, x, w)\
	NAMEDVALUEPROPERTY4(name, datatype, z, z, y, x)\
	NAMEDVALUEPROPERTY4(name, datatype, z, z, y, y)\
	NAMEDVALUEPROPERTY4(name, datatype, z, z, y, z)\
	NAMEDVALUEPROPERTY4(name, datatype, z, z, y, w)\
	NAMEDVALUEPROPERTY4(name, datatype, z, z, z, x)\
	NAMEDVALUEPROPERTY4(name, datatype, z, z, z, y)\
	NAMEDVALUEPROPERTY4(name, datatype, z, z, z, z)\
	NAMEDVALUEPROPERTY4(name, datatype, z, z, z, w)\
	NAMEDVALUEPROPERTY4(name, datatype, z, z, w, x)\
	NAMEDVALUEPROPERTY4(name, datatype, z, z, w, y)\
	NAMEDVALUEPROPERTY4(name, datatype, z, z, w, z)\
	NAMEDVALUEPROPERTY4(name, datatype, z, z, w, w)\
	NAMEDVALUEPROPERTY4(name, datatype, z, w, x, x)\
	NAMEDVALUEPROPERTY4(name, datatype, z, w, x, y)\
	NAMEDVALUEPROPERTY4(name, datatype, z, w, x, z)\
	NAMEDVALUEPROPERTY4(name, datatype, z, w, x, w)\
	NAMEDVALUEPROPERTY4(name, datatype, z, w, y, x)\
	NAMEDVALUEPROPERTY4(name, datatype, z, w, y, y)\
	NAMEDVALUEPROPERTY4(name, datatype, z, w, y, z)\
	NAMEDVALUEPROPERTY4(name, datatype, z, w, y, w)\
	NAMEDVALUEPROPERTY4(name, datatype, z, w, z, x)\
	NAMEDVALUEPROPERTY4(name, datatype, z, w, z, y)\
	NAMEDVALUEPROPERTY4(name, datatype, z, w, z, z)\
	NAMEDVALUEPROPERTY4(name, datatype, z, w, z, w)\
	NAMEDVALUEPROPERTY4(name, datatype, z, w, w, x)\
	NAMEDVALUEPROPERTY4(name, datatype, z, w, w, y)\
	NAMEDVALUEPROPERTY4(name, datatype, z, w, w, z)\
	NAMEDVALUEPROPERTY4(name, datatype, z, w, w, w)\
	NAMEDVALUEPROPERTY4(name, datatype, w, x, x, x)\
	NAMEDVALUEPROPERTY4(name, datatype, w, x, x, y)\
	NAMEDVALUEPROPERTY4(name, datatype, w, x, x, z)\
	NAMEDVALUEPROPERTY4(name, datatype, w, x, x, w)\
	NAMEDVALUEPROPERTY4(name, datatype, w, x, y, x)\
	NAMEDVALUEPROPERTY4(name, datatype, w, x, y, y)\
	NAMEDVALUEPROPERTY4(name, datatype, w, x, y, z)\
	NAMEDVALUEPROPERTY4(name, datatype, w, x, y, w)\
	NAMEDVALUEPROPERTY4(name, datatype, w, x, z, x)\
	NAMEDVALUEPROPERTY4(name, datatype, w, x, z, y)\
	NAMEDVALUEPROPERTY4(name, datatype, w, x, z, z)\
	NAMEDVALUEPROPERTY4(name, datatype, w, x, z, w)\
	NAMEDVALUEPROPERTY4(name, datatype, w, x, w, x)\
	NAMEDVALUEPROPERTY4(name, datatype, w, x, w, y)\
	NAMEDVALUEPROPERTY4(name, datatype, w, x, w, z)\
	NAMEDVALUEPROPERTY4(name, datatype, w, x, w, w)\
	NAMEDVALUEPROPERTY4(name, datatype, w, y, x, x)\
	NAMEDVALUEPROPERTY4(name, datatype, w, y, x, y)\
	NAMEDVALUEPROPERTY4(name, datatype, w, y, x, z)\
	NAMEDVALUEPROPERTY4(name, datatype, w, y, x, w)\
	NAMEDVALUEPROPERTY4(name, datatype, w, y, y, x)\
	NAMEDVALUEPROPERTY4(name, datatype, w, y, y, y)\
	NAMEDVALUEPROPERTY4(name, datatype, w, y, y, z)\
	NAMEDVALUEPROPERTY4(name, datatype, w, y, y, w)\
	NAMEDVALUEPROPERTY4(name, datatype, w, y, z, x)\
	NAMEDVALUEPROPERTY4(name, datatype, w, y, z, y)\
	NAMEDVALUEPROPERTY4(name, datatype, w, y, z, z)\
	NAMEDVALUEPROPERTY4(name, datatype, w, y, z, w)\
	NAMEDVALUEPROPERTY4(name, datatype, w, y, w, x)\
	NAMEDVALUEPROPERTY4(name, datatype, w, y, w, y)\
	NAMEDVALUEPROPERTY4(name, datatype, w, y, w, z)\
	NAMEDVALUEPROPERTY4(name, datatype, w, y, w, w)\
	NAMEDVALUEPROPERTY4(name, datatype, w, z, x, x)\
	NAMEDVALUEPROPERTY4(name, datatype, w, z, x, y)\
	NAMEDVALUEPROPERTY4(name, datatype, w, z, x, z)\
	NAMEDVALUEPROPERTY4(name, datatype, w, z, x, w)\
	NAMEDVALUEPROPERTY4(name, datatype, w, z, y, x)\
	NAMEDVALUEPROPERTY4(name, datatype, w, z, y, y)\
	NAMEDVALUEPROPERTY4(name, datatype, w, z, y, z)\
	NAMEDVALUEPROPERTY4(name, datatype, w, z, y, w)\
	NAMEDVALUEPROPERTY4(name, datatype, w, z, z, x)\
	NAMEDVALUEPROPERTY4(name, datatype, w, z, z, y)\
	NAMEDVALUEPROPERTY4(name, datatype, w, z, z, z)\
	NAMEDVALUEPROPERTY4(name, datatype, w, z, z, w)\
	NAMEDVALUEPROPERTY4(name, datatype, w, z, w, x)\
	NAMEDVALUEPROPERTY4(name, datatype, w, z, w, y)\
	NAMEDVALUEPROPERTY4(name, datatype, w, z, w, z)\
	NAMEDVALUEPROPERTY4(name, datatype, w, z, w, w)\
	NAMEDVALUEPROPERTY4(name, datatype, w, w, x, x)\
	NAMEDVALUEPROPERTY4(name, datatype, w, w, x, y)\
	NAMEDVALUEPROPERTY4(name, datatype, w, w, x, z)\
	NAMEDVALUEPROPERTY4(name, datatype, w, w, x, w)\
	NAMEDVALUEPROPERTY4(name, datatype, w, w, y, x)\
	NAMEDVALUEPROPERTY4(name, datatype, w, w, y, y)\
	NAMEDVALUEPROPERTY4(name, datatype, w, w, y, z)\
	NAMEDVALUEPROPERTY4(name, datatype, w, w, y, w)\
	NAMEDVALUEPROPERTY4(name, datatype, w, w, z, x)\
	NAMEDVALUEPROPERTY4(name, datatype, w, w, z, y)\
	NAMEDVALUEPROPERTY4(name, datatype, w, w, z, z)\
	NAMEDVALUEPROPERTY4(name, datatype, w, w, z, w)\
	NAMEDVALUEPROPERTY4(name, datatype, w, w, w, x)\
	NAMEDVALUEPROPERTY4(name, datatype, w, w, w, y)\
	NAMEDVALUEPROPERTY4(name, datatype, w, w, w, z)\
	NAMEDVALUEPROPERTY4(name, datatype, w, w, w, w)\
	static operator CONCAT2(name, 4)(datatype value){\
		return CONCAT2(name, 4)(value, value, value, value);\
	}\
	static CONCAT2(name, 4) operator + (CONCAT2(name, 4) value0, datatype value1){\
		return CONCAT2(name, 4)(value0.CONCAT2(value_, x) + value1, value0.CONCAT2(value_, y) + value1, value0.CONCAT2(value_, z) + value1, value0.CONCAT2(value_, w) + value1);\
	}\
	static CONCAT2(name, 4) operator + (CONCAT2(name, 4) value0, CONCAT2(name, 4) value1){\
		return CONCAT2(name, 4)(value0.CONCAT2(value_, x) + value1.CONCAT2(value_, x), value0.CONCAT2(value_, y) + value1.CONCAT2(value_, y), value0.CONCAT2(value_, z) + value1.CONCAT2(value_, z), value0.CONCAT2(value_, z) + value1.CONCAT2(value_, w));\
	}\
	static CONCAT2(name, 4) operator - (CONCAT2(name, 4) value0, datatype value1){\
		return CONCAT2(name, 4)(value0.CONCAT2(value_, x) - value1, value0.CONCAT2(value_, y) - value1, value0.CONCAT2(value_, z) - value1, value0.CONCAT2(value_, w) - value1);\
	}\
	static CONCAT2(name, 4) operator - (CONCAT2(name, 4) value0, CONCAT2(name, 4) value1){\
		return CONCAT2(name, 4)(value0.CONCAT2(value_, x) - value1.CONCAT2(value_, x), value0.CONCAT2(value_, y) - value1.CONCAT2(value_, y), value0.CONCAT2(value_, z) - value1.CONCAT2(value_, z), value0.CONCAT2(value_, w) - value1.CONCAT2(value_, w));\
	}\
	static CONCAT2(name, 4) operator - (CONCAT2(name, 4) value){\
		return CONCAT2(name, 4)(-value.CONCAT2(value_, x), -value.CONCAT2(value_, y), -value.CONCAT2(value_, z), -value.CONCAT2(value_, w));\
	}\
	static CONCAT2(name, 4) operator * (CONCAT2(name, 4) value0, datatype value1){\
		return CONCAT2(name, 4)(value0.CONCAT2(value_, x) * value1, value0.CONCAT2(value_, y) * value1, value0.CONCAT2(value_, z) * value1, value0.CONCAT2(value_, w) * value1);\
	}\
	static CONCAT2(name, 4) operator / (CONCAT2(name, 4) value0, datatype value1){\
		if(value1 == 0){\
			throw gcnew System::DivideByZeroException();\
		}\
		return CONCAT2(name, 4)(value0.CONCAT2(value_, x) / value1, value0.CONCAT2(value_, y) / value1, value0.CONCAT2(value_, z) / value1, value0.CONCAT2(value_, w) / value1);\
	}\
	static bool operator != (CONCAT2(name, 4) value0, CONCAT2(name, 4) value1){\
		return value0.CONCAT2(value_, x) != value1.CONCAT2(value_, x) || value0.CONCAT2(value_, y) != value1.CONCAT2(value_, y) || value0.CONCAT2(value_, z) != value1.CONCAT2(value_, z) || value0.CONCAT2(value_, w) != value1.CONCAT2(value_, w);\
	}\
	static bool operator == (CONCAT2(name, 4) value0, CONCAT2(name, 4) value1){\
		return value0.CONCAT2(value_, x) == value1.CONCAT2(value_, x) && value0.CONCAT2(value_, y) == value1.CONCAT2(value_, y) && value0.CONCAT2(value_, z) == value1.CONCAT2(value_, z) && value0.CONCAT2(value_, w) == value1.CONCAT2(value_, w);\
	}\
	static bool operator != (CONCAT2(name, 4) value0, datatype value1){\
		return value0.CONCAT2(value_, x) != value1 || value0.CONCAT2(value_, y) != value1 || value0.CONCAT2(value_, z) != value1 || value0.CONCAT2(value_, w) != value1;\
	}\
	static bool operator == (CONCAT2(name, 4) value0, datatype value1){\
		return value0.CONCAT2(value_, x) == value1 && value0.CONCAT2(value_, y) == value1 && value0.CONCAT2(value_, z) == value1 && value0.CONCAT2(value_, w) == value1;\
	}\
	CONCAT2(name, 4)(datatype x, datatype y, datatype z, datatype w){\
		this->CONCAT2(value_, x) = x;\
		this->CONCAT2(value_, y) = y;\
		this->CONCAT2(value_, z) = z;\
		this->CONCAT2(value_, w) = w;\
	}\
	CONCAT2(name, 4)(datatype x, CONCAT2(name, 3) value){\
		this->CONCAT2(value_, x) = x;\
		this->CONCAT2(value_, y) = value.CONCAT2(value_, x);\
		this->CONCAT2(value_, z) = value.CONCAT2(value_, y);\
		this->CONCAT2(value_, w) = value.CONCAT2(value_, z);\
	}\
	CONCAT2(name, 4)(CONCAT2(name, 3) value, datatype w){\
		this->CONCAT2(value_, x) = value.CONCAT2(value_, x);\
		this->CONCAT2(value_, y) = value.CONCAT2(value_, y);\
		this->CONCAT2(value_, z) = value.CONCAT2(value_, z);\
		this->CONCAT2(value_, w) = w;\
	}\
	CONCAT2(name, 4)(CONCAT2(name, 2) value, datatype z, datatype w){\
		this->CONCAT2(value_, x) = value.CONCAT2(value_, x);\
		this->CONCAT2(value_, y) = value.CONCAT2(value_, y);\
		this->CONCAT2(value_, z) = z;\
		this->CONCAT2(value_, w) = w;\
	}\
	CONCAT2(name, 4)(datatype x, CONCAT2(name, 2) value, datatype w){\
		this->CONCAT2(value_, x) = x;\
		this->CONCAT2(value_, y) = value.CONCAT2(value_, x);\
		this->CONCAT2(value_, z) = value.CONCAT2(value_, y);\
		this->CONCAT2(value_, w) = w;\
	}\
	CONCAT2(name, 4)(datatype x, datatype y, CONCAT2(name, 2) value){\
		this->CONCAT2(value_, x) = x;\
		this->CONCAT2(value_, y) = y;\
		this->CONCAT2(value_, z) = value.CONCAT2(value_, x);\
		this->CONCAT2(value_, w) = value.CONCAT2(value_, y);\
	}\
	CONCAT2(name, 4)(CONCAT2(name, 2) value0, CONCAT2(name, 2) value1){\
		this->CONCAT2(value_, x) = value0.CONCAT2(value_, x);\
		this->CONCAT2(value_, y) = value0.CONCAT2(value_, y);\
		this->CONCAT2(value_, z) = value1.CONCAT2(value_, x);\
		this->CONCAT2(value_, w) = value1.CONCAT2(value_, y);\
	}\
	CONCAT2(name, 4)(datatype value){\
		this->CONCAT2(value_, x) = value;\
		this->CONCAT2(value_, y) = value;\
		this->CONCAT2(value_, z) = value;\
		this->CONCAT2(value_, w) = value;\
	}\
};



#define NAMEDDATATYPEVECTOR(name, datatype)\
NAMEDDATATYPE2(name, datatype)\
NAMEDDATATYPE3(name, datatype)\
NAMEDDATATYPE4(name, datatype)



namespace fDatatypes {


	NAMEDDATATYPEVECTOR(byte, Byte)
	NAMEDDATATYPEVECTOR(uint, UInt32)
	NAMEDDATATYPEVECTOR(sbyte, SByte)


}