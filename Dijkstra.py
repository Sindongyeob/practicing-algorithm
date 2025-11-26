#그래프의 노드와 가중치를 포함한 엣지를 인접 리스트, 딕셔너리로 표현
import heapq

# 그래프의 노드와 가중치를 포함한 엣지를 인접 리스트, 딕셔너리로 표현
graph = {
    'v0': [('v1', 10), ('v2', 17), ('v3', 30), ('v4', 23), ('v5', 25)],
    'v1': [('v2', 20)],
    'v2': [('v5', 17)],
    'v3': [('v1', 19), ('v6', 24)],
    'v4': [('v3', 16), ('v5', 28), ('v6', 18)],
    'v5': [('v7', 39), ('v8', 25)],
    'v6': [('v9', 20)],
    'v7': [('v4', 20), ('v9', 28)],
    'v8': [('v7', 29)],
    'v9': [('v8', 40)]
}


def dijkstra(graph, start, end):
    # 각 노드까지의 최단 거리를 저장 (초기값: 시작점(0), 나머지(무한대))
    distances = {node: float('inf') for node in graph}
    distances[start] = 0

    # 각 노드의 이전 노드를 저장 (경로 추적용)
    previous = {node: None for node in graph}

    # 우선순위 큐: (거리, 노드)
    pq = [(0, start)]
    visited = set()

    while pq:
        current_dist, current_node = heapq.heappop(pq)

        # 이미 방문한 노드는 스킵
        if current_node in visited:
            continue

        visited.add(current_node)

        # 목적지에 도달하면 종료
        if current_node == end:
            break

        # 현재 노드의 인접 노드들을 확인
        for neighbor, weight in graph[current_node]:
            if neighbor in visited:
                continue

            # 새로운 거리 계산
            new_dist = current_dist + weight

            # 더 짧은 경로를 발견하면 업데이트
            if new_dist < distances[neighbor]:
                distances[neighbor] = new_dist
                previous[neighbor] = current_node
                heapq.heappush(pq, (new_dist, neighbor))

    # 경로 재구성
    path = []
    current = end
    while current is not None:
        path.append(current)
        current = previous[current]
    path.reverse()

    return distances[end], path

start= 'v0'
end = 'v9'
weight, shortest_path = dijkstra(graph, start, end)
print(f"최단경로: <{', '.join(shortest_path)}>, 경로의 가중치: {weight}")
