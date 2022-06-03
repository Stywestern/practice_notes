import random


def make_password(*args):
    if isinstance(args[0], list):
        new_list = args[0]
        return "".join(new_list)
    else:
        listed_args = list(args)
        if not(all(isinstance(element, str) for element in listed_args)):
            listed_args = []
            for element in args:
                listed_args.append(str(element))
        else:
            pass
        random.shuffle(listed_args)
        return "".join(listed_args)


password1 = make_password("kerem", "ışık", "assfqw", 12, True)
print(password1)
print("-----------------------------------------------")
password2 = make_password("kerem", "ışık", "assfqw")
print(password2)
print("-----------------------------------------------")
password3 = make_password(["kerem", "ışık", "assfqw"])
print(password3)
