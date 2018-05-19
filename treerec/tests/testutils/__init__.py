import msprime
import unittest

class TestSlimOutput(unittest.TestCase):

    def get_slim_ids(self, ts):
        # get SLiM ID -> msprime ID map from metadata
        ids = {}
        for n in ts.nodes():
            meta = n.metadata.decode('utf8').split(",")
            slim_id = int(meta[0])
            ids[slim_id] = n.id
        return ids
