    #opening file
try:
    file = open("Berkeley.csv", 'r')
    
    #list will contain total data
    #output will contain only the admitted female frequency of all departments
    
    list = []
    output = []

    # Storing each line in file to list
    for i in file:
        list.append(i)

    # splitting the first 14 characters of each index
    for i, l in enumerate(list):
        if l[0:15] == "Admitted,Female":
            output.append(l)

    for i in output:
        print(i)

except IOError:
    print("file not found")

finally:
    file.close()
