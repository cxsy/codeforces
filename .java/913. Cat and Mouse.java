import java.util.*;

class Solution {
  public int catMouseGame(int[][] graph) {
    int N = graph.length;
    final int DRAW = 0, MOUSE = 1, CAT = 2;

    int[][][] color = new int[50][50][2];
    int[][][] degree = new int[50][50][2];
    // degree[node] : the number of neutral children of this node
    Queue<int[]> queue = new LinkedList();
    for (int m = 0; m < N; ++m) {

      for (int c = 0; c < N; ++c) {
        degree[m][c][0] = graph[m].length;
        degree[m][c][1] = graph[c].length;
      }
      for (int x : graph[0]) {
        degree[m][x][1]--;
      }
    }

    for (int i = 0; i < N; ++i) {
      for (int t = 0; t <= 1; ++t) {
        color[0][i][t] = MOUSE;
        queue.add(new int[] { 0, i, t, MOUSE });
        if (i > 0) {
          color[i][i][t] = CAT;
          queue.add(new int[] { i, i, t, CAT });
        }
      }
    }
    // enqueued : all nodes that are colored
    // percolate
    while (!queue.isEmpty()) {
      // for nodes that are colored :
      int[] node = queue.remove();
      int i = node[0], j = node[1], t = node[2], c = node[3];
      // for every parent of this node i, j, t :
      for (int[] parent : parents(graph, i, j, t)) {
        int i2 = parent[0], j2 = parent[1], t2 = parent[2];
        // if this parent is not colored :
        if (color[i2][j2][t2] == DRAW) {
          // if the parent can make a winning move (ie. mouse to MOUSE), do so
          if (t2 == c - 1) {
            color[i2][j2][t2] = c;
            queue.add(new int[] { i2, j2, t2, c });
          } else {
            // else, this parent has degree[parent]--, and enqueue
            // if all children of this parent are colored as losing moves
            degree[i2][j2][t2]--;
            if (degree[i2][j2][t2] == 0) {
              color[i2][j2][t2] = c;
              queue.add(new int[] { i2, j2, t2, c });
            }
          }
        }
      }
    }

    return color[1][2][0];
  }

  // What nodes could play their turn to
  // arrive at node (m, c, t) ?
  public List<int[]> parents(int[][] graph, int m, int c, int t) {
    List<int[]> ans = new ArrayList();
    if (t == 1) {
      for (int m2 : graph[m])
        ans.add(new int[] { m2, c, 1 - t });
    } else {
      for (int c2 : graph[c])
        if (c2 > 0)
          ans.add(new int[] { m, c2, 1 - t });
    }
    return ans;
  }
}