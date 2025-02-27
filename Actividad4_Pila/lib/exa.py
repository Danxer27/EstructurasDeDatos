classes = [57,62,67,72,77,82,87,92]
fr = [2,8,12,15,21,17,11,5]

sum = 0;
n = len(classes)
def media():
    for i in range(0, n):
        sum += classes[i] * fr[i]
        
    media = sum / n
    print(media)