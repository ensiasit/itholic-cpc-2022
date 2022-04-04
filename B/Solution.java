// Author: El Mehdi ASSALI
// Original: https://codeforces.com/contest/645/problem/D

import java.util.*;

public class Solution {
  static class Edge {
    Vertex to;
    int order;

    Edge(Vertex to, int order) {
      this.to = to;
      this.order = order;
    }
  }

  static class Vertex {
    int longestPath, maxOrder;
    List<Edge> adj = new ArrayList<>();

    int dfs() {
      if (longestPath != 0) {
        return longestPath;
      }

      longestPath = 1;

      for (Edge next : adj) {
        if (next.to.dfs() + 1 > longestPath) {
          longestPath = next.to.longestPath + 1;
          maxOrder = Math.max(next.to.maxOrder, next.order);
        }
      }

      return longestPath;
    }
  }

  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);

    int n = in.nextInt(), m = in.nextInt();
    Vertex[] graph = new Vertex[n + 1];

    for (int i = 1; i <= n; i++) {
      graph[i] = new Vertex();
    }

    for (int i = 1; i <= m; i++) {
      int from = in.nextInt(), to = in.nextInt();

      graph[from].adj.add(new Edge(graph[to], i));
    }

    for (int i = 1; i <= n; i++) {
      if (graph[i].dfs() == n) {
        System.out.println(graph[i].maxOrder);
        return;
      }
    }

    System.out.println(-1);
  }
}