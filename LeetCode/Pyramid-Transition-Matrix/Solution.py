
from functools import cache


class Solution:
    def pyramidTransition(self, bottom: str, allowed: List[str]) -> bool:
        # build up potential values for next rows based on allowed values
        tops = defaultdict(list)
        for key in allowed:
            tops[key[:2]].append(key[2])

        def gen_next_rows(full_items, all_valid=set(), i=0, cur=''):
            # handle when a base pair does not have a top option in allowed
            if any([item == [] for item in full_items]):
                return []

            # generated a full new line, add to set of valid options
            if i == len(full_items):
                all_valid.add(cur)
                return

            # full line is not complete, for each top option of current base pair,
            # use it and look at the options for the next base pair.
            for item in full_items[i]:
                gen_next_rows(full_items, all_valid, i + 1, cur + item)

            # all row options generated, return the options
            return all_valid

        seen = set()

        def find_next_row(last):
            n = len(last)
            # made it to the top with a valid top option for the row of length 2
            if n == 1:
                return True

            # Generate all potential options for the next row and try them.
            # For example 2: the list comprehension used in gen_next_rows would be
            # [['B', 'C'], ['B', 'C'], ['B', 'C']] for the next row choices after bottom
            options = gen_next_rows([tops[last[i:i + 2]] for i in range(n - 1)], set())

            # cache is useful here because the same sequence may appear more than once
            # as the pyramid builds up.
            for option in options:
                if option in seen:
                    continue
                if find_next_row(option):
                    return True
                seen.add(option)
            return False
        return find_next_row(bottom)
