import unittest
from elemInList import elemInList


class TestElemInList(unittest.TestCase):
    def testElemInListEmpty(self):
        self.assertFalse(elemInList([], None))

    def testElemInList1Elem(self):
        self.assertTrue(elemInList([1], 1))

    def testElemInListNElem(self):
        self.assertTrue(elemInList([1, 2, 3, 4, 5], 4))

    def testElemInListFalse(self):
        self.assertFalse(elemInList([1, 2, 3], 4))


if __name__ == '__main__':
    unittest.main()
