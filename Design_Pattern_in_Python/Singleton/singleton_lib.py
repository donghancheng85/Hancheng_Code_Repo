from typing import Callable


def is_singleton(factory: Callable[[], None]) -> bool:
    first_create = factory()
    second_create = factory()

    if first_create is second_create:
        return True
    else:
        return False
