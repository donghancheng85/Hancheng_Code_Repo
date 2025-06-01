import unittest
from Factory.factory_lib import PersonFactory


class Evaluate(unittest.TestCase):
    def test_exercise(self):
        pf = PersonFactory()

        p1 = pf.create_person("Chris")
        self.assertEqual(p1.name, "Chris")
        self.assertEqual(p1.id, 0)

        p2 = pf.create_person("Sarah")
        self.assertEqual(p2.id, 1)


if __name__ == "__main__":
    unittest.main()
