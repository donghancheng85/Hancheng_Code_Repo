import unittest
from Adapter.adapter_lib import (
    Square,
    calculate_area,
    SquareToRectangleAdapter,
)


class Evaluate(unittest.TestCase):
    def test_exercise(self):
        sq = Square(11)
        adapter = SquareToRectangleAdapter(sq)
        self.assertEqual(121, calculate_area(adapter))
        sq.side = 10
        self.assertEqual(100, calculate_area(adapter))


if __name__ == "__main__":
    unittest.main()
