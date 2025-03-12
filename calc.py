oneone = [0.00512395, 0.0051244,  0.00500122]
onetwo = [0.00356875, 0.00367536, 0.00405483]
onefour = [0.00287683, 0.00272203, 0.00308394]
oneeight = [0.00185082, 0.00226172, 0.00164343]

totalTests = [oneone, onetwo, onefour, oneeight]

testN = 1
for test in totalTests:
    temp = 0
    for result in test:
        temp += result
    average = temp / len(test)
    print(f"Average for {testN}: {average}")
    testN += 1
