import json
import sys
from random import shuffle

assigning = True
def assignValues(value):
    global assigning
    if assigning == False:
        return value

    if len(value.keys()) == 1:
        for i in range(100):
            print
        print assigning
        print "Adjective:", value["Word"]
        print
    
        print "Morailty:"
        print "Good-Bad from 7-(-7)"
        print "Variance from 0 to 7"
        print "#,#"
        morality = list(input())
        value["Morality"] = morality
        print
    
        print "Strength:"
        print "Strong-Weak from 7-0"
        print "Variance from 0 to 7"
        print "#,#"
        strength = list(input())
        value["Strength"] = strength
        print

        print "Tags:"
        print "Space seperated list"
        tags = raw_input().lower().split(' ')
        value["Tags"] = tags
        print

        print "Continue?" 
        print "Enter 'n' to stop"
        if len(raw_input()) > 0:
            assigning = False

    return value

data = json.load(file(sys.argv[1]))

shuffle(data["Adjectives"])

data["Adjectives"] = map(assignValues, data["Adjectives"])

data["Adjectives"] = sorted(data["Adjectives"], key=lambda x: x["Word"])

with file(sys.argv[1], 'w') as f:
    f.write(json.dumps(data, sort_keys = True, indent = 4))

