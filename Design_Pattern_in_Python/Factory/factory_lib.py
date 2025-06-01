class Person:
    def __init__(self, id: int, name: str):
        self.id = id
        self.name = name

    def __str__(self):
        return f"Person name: {self.name}\n" f"Person id : {self.id}"


class PersonFactory:
    person_id: int = 0

    def create_person(self, name: str) -> Person:
        return_value = Person(PersonFactory.person_id, name)
        PersonFactory.person_id += 1
        return return_value
