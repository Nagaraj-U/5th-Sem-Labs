my_list = [2,7,9,12]
def maximum(my_list):
    if(len(my_list) == 1):
        return my_list[0]
    return max(my_list[0],maximum(my_list[1:]))
print(maximum(my_list))
