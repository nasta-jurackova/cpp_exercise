import sqlite3

class JewelleryStore:
    def __init__(self, path):
        self.connection = sqlite3.connect(path)
        self.cursor = self.connection.cursor()
        self.stone_id = 0
        self.ring_id = 0
        self.assignment_id = 0
        tables = [ """CREATE TABLE Stones (
                      id INTEGER PRIMARY KEY
                      width REAL
                      height REAL
                      color TEXT );
                   """,
                   """CREATE TABLE Rings (
                      id INTEGER PRIMARY KEY );
                   """,
                   """CREATE TABLE Assignment (
                      id INTEGER PRIMARY KEY
                      FOREIGN KEY (ring_id) REFERENCES Rings (id)
                      FOREIGN KEY (stone_id) REFERENCES Stones (id) );
                   """
        ]
        for create in tables:
            self.cursor.execute(create)

    def add_stone(self, width, height, color): # -> stone_id
        to_execute = """INSERT INTO Stones VALUE (?, ?, ?, ?)"""
        self.stone_id += 1
        self.cursor.execute(to_execute, (self.stone_id, width, height, color))

    def get_stone(self, stone_id): # -> (width, height, color)
        to_execute = """SELECT width, height, color FROM Stones WHERE id = ?"""
        self.cursor.execute(to_execute, (stone_id,))
        width, height, color = self.cursor.fetchone()
        return (width, height, color)

    def add_ring(self, stone_id_list): # -> ring_id
        to_execute = """INSERT INTO Rings VALUE (?)"""
        self.ring_id += 1
        self.cursor.execute(to_execute, (self.ring_id,))
        for id in stone_id_list:
            to_execute = """INSERT INTO Assignment VALUE (?, ?)"""
            self.cursor.execute(to_execute, (self.ring_id, id))

    def get_ring(self, ring_id): # -> [(stone_id,), ...]
        to_execute = """SELECT stone_id FROM Assignment WHERE ring_id = ?"""
        self.cursor.execute(to_execute, (ring_id,))
        return list(map(lambda x: x[0], self.cursor.fetchall()))

    def get_rings_with_stone(self, stone_id): # ->[ring_id, ...]
        to_execute = """SELECT Rings.id FROM
                        Stones NATURAL JOIN Assignment ON Stones.id = Assignment.stone_id
                        NATURAL JOIN Rings ON Assignment.ring_id = Rings.id
                        WHERE Assignment.stone_id = ?"""
        self.cursor.execute(to_execute, (stone_id,))
        return self.cursor.fetchall()

    def get_rings_with_no_stone(self): # -> [ring_id, ...]
        to_execute = """SELECT Rings.id AS ring_id FROM
                        Rings LEFT JOIN Assignment ON Rings.id = Assignment.ring_id
                        WHERE stone_id IS NULL"""
        self.cursor.execute(to_execute)
        return self.cursor.fetchall()

    def close(self):
        self.connection.commit()
        self.connection.close()
