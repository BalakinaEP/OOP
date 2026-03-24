#include "CppUnitTest.h"
#include "../Project1/Complex.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tests
{
	TEST_CLASS(ComplexTests)
	{
	public:
		
		TEST_METHOD(Create_element_success)
		{
			//Arrage
			double re = 1.0;
			double im = -3.0;

			//Act
			Complex c(re, im);

			//Assert
			Assert::AreEqual(c.getRe(), re);
			Assert::AreEqual(c.getIm(), im);
		}
		TEST_METHOD(Sum_Complex_Success)
		{
			//Arrage
			double re1 = 1.0;
			double im1 = -3.0;
			double re2 = -1.0;
			double im2 = 3.0;

			//Act
			Complex c1(re1, im1);
			Complex c2(re2, im2);
			Complex result = c1 + c2;
			//Assert
			Assert::AreEqual(result.getRe(), re1+re2);
			Assert::AreEqual(result.getIm(), im1 + im2);
		}
	};
}
