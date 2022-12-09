print(" ")
# we could use all fonction with this way
name = input("What's your name?").strip().title()

# split user's name into first and last name
first, last = name.split(" ")


print(f"Hello {name}")  #f say to python there is a special string
print(f"Hello {first}")
