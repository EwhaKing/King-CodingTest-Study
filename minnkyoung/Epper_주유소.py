def solution(cities, distance, price):
    cost = 0
    min_cost = price[0]

    for i in range(cities - 1):
        if price[i] < min_cost:
            min_cost = price[i]
        cost += min_cost * distance[i]
    return cost

if __name__=='__main__':
    cities = int(input())
    distance = list(map(int, input().split()))
    price = list(map(int, input().split()))
    print(solution(cities, distance, price))