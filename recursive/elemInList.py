def elemInList(myList, elem):
    if len(myList) == 0:
        return False
    return True if myList[0] == elem else elemInList(myList[1:], elem)
