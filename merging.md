# aggregating findata

## simple case

Aggregate sumvals on
rule 1 level,
which is often the same as sub ID.
| Main ID | sub ID | subsub ID | rule 1 | rule 2 | rule 3 | value 1 | value 2 | value 3 | sumval 1 | sumval 2 | sumval 3 | valid |
| ------- | ------ | --------- | ------ | ------ | ------ | ------- | ------- | ------- | -------- | -------- | -------- | ----- |
| 01      | A      | 1         | r1A    | r2A    | r3A    | 1       | 10      | 100     | 1        | 3        | 2        | True  |
| 01      | A      | 2         | r1A    | r2A    | r3A    | 1       | 10      | 100     | 2        | 4        | 3        | True  |
| 01      | A      | 3         | r1A    | r2A    | r3A    | 3       | 30      | 300     | 3        | 5        | 4        | True  |
| 01      | B      | 1         | r1B    | r2B    | r3B    | 3       | 30      | 300     | 4        | 6        | 5        | True  |
| 01      | B      | 2         | r1B    | r2B    | r3B    | 3       | 30      | 300     | 5        | 7        | 6        | True  |

this is aggreated to
| Main ID | sub IDs               | rule 1 | rule 2 | rule 3 | value 1 | value 2 | value 3 | sumval 1 | sumval 2 | sumval 3 |
| ------- | --------------------- | ------ | ------ | ------ | ------- | ------- | ------- | -------- | -------- | -------- |
| 01      | [(A,1), (A,2), (A,3)] | r1A    | r2A    | r3A    | 1       | 10      | 100     | 6        | 12       | 9        |
| 01      | [(B,1), (B,2)]        | r1B    | r2B    | r3B    | 3       | 30      | 300     | 9        | 13       | 11       |

Calculated values:
| Main ID | sub IDs               | rule 1 | rule 2 | rule 3 | value 1 | value 2 | value 3 | sumval 1 | sumval 2 | sumval 3 | weight | result |
| ------- | --------------------- | ------ | ------ | ------ | ------- | ------- | ------- | -------- | -------- | -------- | ------ | ------ |
| 01      | [(A,1), (A,2), (A,3)] | r1A    | r2A    | r3A    | 1       | 10      | 100     | 6        | 12       | 9        | 21     | 42     |
| 01      | [(B,1), (B,2)]        | r1B    | r2B    | r3B    | 3       | 30      | 300     | 9        | 13       | 11       | 24     | 24     |

Allocated values:
| Main ID | sub ID | subsub ID | rule 1 | rule 2 | rule 3 | value 1 | value 2 | value 3 | sumval 1 | sumval 2 | sumval 3 | valid | weight | result |
| ------- | ------ | --------- | ------ | ------ | ------ | ------- | ------- | ------- | -------- | -------- | -------- | ----- | ------ | ------ |
| 01      | A      | 1         | r1A    | r2A    | r3A    | 1       | 10      | 100     | 1        | 3        | 2        | True  | 5      | 10     |
| 01      | A      | 2         | r1A    | r2A    | r3A    | 1       | 10      | 100     | 2        | 4        | 3        | True  | 7      | 14     |
| 01      | A      | 3         | r1A    | r2A    | r3A    | 3       | 30      | 300     | 3        | 5        | 4        | True  | 9      | 18     |
| 01      | B      | 1         | r1B    | r2B    | r3B    | 3       | 30      | 300     | 4        | 6        | 5        | True  | 11     | 11     |
| 01      | B      | 2         | r1B    | r2B    | r3B    | 3       | 30      | 300     | 5        | 7        | 6        | True  | 13     | 13     |

## If invalid data is present

Don't aggregate rows if valid == False
| Main ID | sub ID | subsub ID | rule 1 | rule 2 | rule 3 | value 1 | value 2 | value 3 | sumval 1 | sumval 2 | sumval 3 | valid | weight |
| ------- | ------ | --------- | ------ | ------ | ------ | ------- | ------- | ------- | -------- | -------- | -------- | ----- | ------ |
| 02      | A      | 1         | r1A    | r2A    | r3A    | 1       | 10      | 100     | 1        | 3        | 2        | True  | 5      |
| 02      | A      | 2         | r1A    | r2A    | r3A    | 1       | 10      | 100     | 2        | 4        | 3        | True  | 7      |
| 02      | A      | 3         | r1A    | r2A    | r3A    | 1       | 10      | 100     | 2        | 4        | 3        | False | 7      |

this is aggreated to
| Main ID | sub IDs        | rule 1 | rule 2 | rule 3 | value 1 | value 2 | value 3 | sumval 1 | sumval 2 | sumval 3 | weight |
| ------- | -------------- | ------ | ------ | ------ | ------- | ------- | ------- | -------- | -------- | -------- | ------ |
| 02      | [(A,1), (A,2)] | r1A    | r2A    | r3A    | 1       | 10      | 100     | 3        | 7        | 5        | 12     |

Calculated values:
| Main ID | sub IDs        | rule 1 | rule 2 | rule 3 | value 1 | value 2 | value 3 | sumval 1 | sumval 2 | sumval 3 | weight | result |
| ------- | -------------- | ------ | ------ | ------ | ------- | ------- | ------- | -------- | -------- | -------- | ------ | ------ |
| 02      | [(A,1), (A,2)] | r1A    | r2A    | r3A    | 1       | 10      | 100     | 3        | 7        | 5        | 12     | 36     |

Allocated values
| Main ID | sub ID | subsub ID | rule 1 | rule 2 | rule 3 | value 1 | value 2 | value 3 | sumval 1 | sumval 2 | sumval 3 | valid | weight | result |
| ------- | ------ | --------- | ------ | ------ | ------ | ------- | ------- | ------- | -------- | -------- | -------- | ----- | ------ | ------ |
| 02      | A      | 1         | r1A    | r2A    | r3A    | 1       | 10      | 100     | 1        | 3        | 2        | True  | 5      | 15     |
| 02      | A      | 2         | r1A    | r2A    | r3A    | 1       | 10      | 100     | 2        | 4        | 3        | True  | 7      | 21     |
| 02      | A      | 3         | r1A    | r2A    | r3A    | 1       | 10      | 100     | 2        | 4        | 3        | False | 7      | NA     |

## if granularity mismatch

If rule 2 or 3 is not the same within rule 1,
print a log warning,
and sum value 2 or 3 too
| Main ID | sub ID | subsub ID | rule 1 | rule 2 | rule 3 | value 1 | value 2 | value 3 | sumval 1 | sumval 2 | sumval 3 | valid |
| ------- | ------ | --------- | ------ | ------ | ------ | ------- | ------- | ------- | -------- | -------- | -------- | ----- |
| 03      | C      | 1         | r1C    | r2C    | r3C    | 1       | 10      | 100     | 1        | 3        | 2        | True  |
| 03      | C      | 2         | r1C    | r2D    | r3C    | 1       | 20      | 100     | 2        | 4        | 3        | True  |
| 03      | C      | 3         | r1C    | r2E    | r3C    | 1       | 30      | 100     | 3        | 5        | 4        | True  |
| 03      | D      | 1         | r1D    | r2F    | r3D    | 3       | 40      | 300     | 4        | 6        | 5        | True  |
| 03      | D      | 2         | r1D    | r2F    | r3D    | 3       | 40      | 300     | 5        | 7        | 6        | True  |

this is aggreated to
| Main ID | sub IDs               | rule 1 | rule 2          | rule 3 | value 1 | value 2 | value 3 | sumval 1 | sumval 2 | sumval 3 |
| ------- | --------------------- | ------ | --------------- | ------ | ------- | ------- | ------- | -------- | -------- | -------- |
| 03      | [(C,1), (C,2), (C,3)] | r1C    | [r2C, r2D, r2E] | r3C    | 1       | 60      | 100     | 6        | 12       | 9        |
| 03      | [(D,1), (D,2)]        | r1D    | r2F             | r3D    | 3       | 40      | 300     | 9        | 13       | 11       |

## same rule across different Main ID

Aggregation is limited by Main ID
| Main ID | sub ID | subsub ID | rule 1 | rule 2 | rule 3 | value 1 | value 2 | value 3 | sumval 1 | sumval 2 | sumval 3 | valid |
| ------- | ------ | --------- | ------ | ------ | ------ | ------- | ------- | ------- | -------- | -------- | -------- | ----- |
| 04      | A      | 1         | r1A    | r2A    | r3A    | 1       | 10      | 100     | 1        | 3        | 2        | True  |
| 04      | A      | 2         | r1A    | r2A    | r3A    | 1       | 10      | 100     | 2        | 4        | 3        | True  |
| 05      | A      | 1         | r1A    | r2A    | r3A    | 1       | 10      | 100     | 3        | 5        | 4        | True  |
| 05      | A      | 2         | r1A    | r2A    | r3A    | 1       | 10      | 100     | 4        | 6        | 5        | True  |

this is aggreated to
| Main ID | sub IDs        | rule 1 | rule 2 | rule 3 | value 1 | value 2 | value 3 | sumval 1 | sumval 2 | sumval 3 |
| ------- | -------------- | ------ | ------ | ------ | ------- | ------- | ------- | -------- | -------- | -------- |
| 03      | [(A,1), (A,2)] | r1A    | r2A    | r3A    | 1       | 10      | 100     | 3        | 7        | 5        |
| 04      | [(A,1), (A,2)] | r1A    | r2A    | r3A    | 1       | 10      | 100     | 7        | 11       | 9        |
