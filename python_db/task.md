# Simple python database

You will write a simple database for jewellery store.

- To start, create a class JewelleryStore.
    - It's initializer takes string ... the path to sqlite3 database file
    - It opens the database in creates all the necessary tables, if they do not exist
- Define also `close()` method, that commits the changes and closes the connection to database. (Yes, in C++, you could use RAII :D).

Database should contain this:
- 'Stones':
    - width (float)
    - height (float)
    - color (string)
- 'Rings':
    - Any number of stones


You can of course create more tables, or distribute the information however you like.

Methods that should be implemented:
    - add_stone(width, height, color) -> stone_id
    - get_stone(stone_id) -> (width, height, color)
    - add_ring([stone_id, ...]) -> ring_id
    - get_ring(ring_id) -> [stone_id, ...]
    - get_rings_with_stone(stone_id) ->[ring_id, ...]
    - get_rings_with_no_stone() -> [ring_id, ...]