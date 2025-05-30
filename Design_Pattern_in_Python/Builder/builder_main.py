class CodeBuilder:
    def __init__(self, root_name: str):
        self.root_name = root_name
        self.types_and_names = {}

    def add_field(self, type: str, name: str) -> "CodeBuilder":
        self.types_and_names[type] = name
        return self

    def __str__(self):
        return_string = f"class {self.root_name}:\n"
        
        if not self.types_and_names:
            return_string += "  pass"
        else:
            return_string += "  def __init__(self):\n"
            for type, name in self.types_and_names.items():
                return_string += f"    self.{type} = {name}\n"
        
        return return_string

if __name__ == "__main__":
    cb = CodeBuilder('Person').add_field('name', '""') \
                          .add_field('age', '0')
    print(cb)