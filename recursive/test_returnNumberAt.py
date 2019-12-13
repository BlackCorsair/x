import unittest
from returnNumberAt import digitAt

class TestPositionAt(unittest.TestCase):
    def testDigitAt1(self):
        returned = digitAt(123, 1)
        self.assertEqual(3, returned, f"{returned} is not 3 for 123, 1")

    def testDigitAt2(self):
        returned = digitAt(123, 2)
        self.assertEqual(2, returned, f"{returned} is not 2 for 123, 2")
        
    def testDigitAt3(self):
        returned = digitAt(123, 3)
        self.assertEqual(1, returned, f"{returned} is not 1 for 123, 3")

if __name__ == '__main__':
    unittest.main()
