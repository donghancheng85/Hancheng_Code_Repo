import unittest
from singleton_exercise.singleton_lib import is_singleton
from copy import deepcopy


class Evaluate(unittest.TestCase):
    def test_singleton(self):
        obj = [1, 2, 3]
        self.assertTrue(is_singleton(lambda: obj))
        self.assertFalse(is_singleton(lambda: deepcopy(obj)))


if __name__ == "__main__":
    unittest.main()
