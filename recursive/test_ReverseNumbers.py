import unittest
from reverseNumbers import reverseNumber


class TestReverseNumbers(unittest.TestCase):
    def testReverseNumberBase(self):
        self.assertEqual(1, reverseNumber(1))

    def testReverseNumberGeneral2(self):
        self.assertEqual(12, reverseNumber(21))

    def testReverseNumbersDifferent(self):
        self.assertEqual(321, reverseNumber(123))

    def testReverseNumbersEquals(self):
        self.assertEqual(2222, reverseNumber(2222))

    def testReverseNumbersMix(self):
        self.assertEqual(543321, reverseNumber(123345))


if __name__ == "__main__":
    unittest.main()
