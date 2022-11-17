#include "graph_class.h"

/* TEST FOR MY DIJKSTRA IMPLEMENTATION WITH PQ*/
void dijkstra_test(){
	cout << endl;
	cout << "   ---   Dijkstra Test   ---   " << endl;
	Graph graph(6);
	vector<int> path(6), dist(6);

	graph.addWeightedEdge(0, 1, 10);
	graph.addWeightedEdge(0, 5, 8);
	graph.addWeightedEdge(1, 3, 2);
	graph.addWeightedEdge(2, 1, 1);
	graph.addWeightedEdge(3, 2, 2);
	graph.addWeightedEdge(4, 1, 4);
	graph.addWeightedEdge(4, 3, 1);
	graph.addWeightedEdge(5, 4, 1);

    graph.print();
	cout << endl;
	cout << "Using Dijkstra" << endl;
	graph.dijkstra(0, path, dist);
	for (int i = 0; i < 6; i++) {
		cout << "Distance from 0 to " << i << " is " << dist[i] << endl;
	}
	cout << endl;
	cout << "Using Dijkstra PQ: " << endl;

	graph.dijkstra_pq(0, path, dist);
	for (int i = 0; i < 6; i++) {
		cout << "Distance from 0 to " << i << " is " << dist[i] << endl;
	}
	cout << "   ---   -------------   ---   " << endl;
	cout << endl;
}

/* TEST FOR TESTING BELLMAN-FORD  */
void bellman_ford_test(){
	cout << endl;
	cout << "   ---   Bellman  Test   ---   " << endl;
	Graph graph(6);
	vector<int> path(6), dist(6);
	//  Graph for Bellman-ford (From video)
	graph.addWeightedEdge(0, 1, 10);
	graph.addWeightedEdge(0, 5, 8);
	graph.addWeightedEdge(1, 3, 2);
	graph.addWeightedEdge(2, 1, 1);
	graph.addWeightedEdge(3, 2, -2);
	graph.addWeightedEdge(4, 3, -1);
	graph.addWeightedEdge(4, 1, -4);
	graph.addWeightedEdge(5, 4, 1);
	
	graph.print();

	cout << graph.edges() <<endl;

	cout << endl;
	cout << "Bellman Ford finds the right path and detects the cycle: " << endl;
	graph.bellman_ford(0, path, dist);
	for (int i = 0; i < 6; i++) {
		cout << "Distance from 0 to " << i << " is " << dist[i] << endl;
	}
	cout <<endl;
	
	cout << "---   Testing for neggative weight cycle:   ---" << endl;
	Graph neg_cyc_graph(3);
	vector <int> neg_cyc_path(3), neg_cyc_dist(3);
	neg_cyc_graph.addWeightedEdge(0, 1, 8);
	neg_cyc_graph.addWeightedEdge(1, 2, -6);
	neg_cyc_graph.addWeightedEdge(2, 0, -5);
	cout << "Dijkstra does not detect negative weight cycle: " << endl;
	neg_cyc_graph.dijkstra(0, neg_cyc_path, neg_cyc_dist);
	for (int i = 0; i < 3; i++) {
		cout << "Distance from 0 to " << i << " is " << neg_cyc_dist[i] << endl;
	}
	cout<<endl;
	cout << "Whereas Bellman-Ford does: " << endl;
	neg_cyc_graph.bellman_ford(0, neg_cyc_path, neg_cyc_dist);
	for (int i = 0; i < 3; i++) {
		cout << "Distance from 0 to " << i << " is " << neg_cyc_dist[i] << endl;
	}
	cout<<endl;

}

void dag_test(){
	cout << "   ---  Topologic test   ---   " <<endl;
	//Graph for testing dijsktra vs dijkstra_pq vs top
	Graph digraph(7);
	vector <int> path(7), dist(7);

    digraph.addWeightedEdge(0, 1, 1);
	digraph.addWeightedEdge(0, 2, 1);
	digraph.addWeightedEdge(1, 3, 1);
	digraph.addWeightedEdge(2, 3, 1);
	digraph.addWeightedEdge(3, 4, 1);
	digraph.addWeightedEdge(3, 5, 1);
	digraph.addWeightedEdge(4, 6, 1);
	digraph.addWeightedEdge(5, 6, 1);
    digraph.print();

	cout<<endl;
	cout << "Topological sort: ";
	digraph.topologicalSort(0);
	cout << endl;
	cout << endl;
	
	cout << "Topological Dijkstra" << endl;
	digraph.topological_dijkstra(0, path, dist);
	for (int i = 0; i < 7; i++) {
		cout << "Distance from 0 to " << i << " is " << dist[i] << endl;
	}
	cout << endl;
	cout << endl;
	cout << "Dijkstra" << endl;
	digraph.dijkstra_pq(0, path, dist);
	for (int i = 0; i < 7; i++) {
		cout << "Distance from 0 to " << i << " is " << dist[i] << endl;
	}


	cout << "   ---   -------------   ---   " << endl;
	cout << endl;
	cout << "   ---   -------------   ---   " << endl;
	cout<< endl;
}


// Driver code
int main() {
	/*	TO RUN CODE USE COMMANDS IN TERMINAL: */
	//	minGW32-make
	// -\test
	
	dijkstra_test();
	bellman_ford_test();
	dag_test();
	
    return 0;
}
