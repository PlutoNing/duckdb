from sqllogic_parser.base_statement import BaseStatement
from sqllogic_parser.token import Token


class Require(BaseStatement):
    def __init__(self, header: Token):
        super().__init__(header)
