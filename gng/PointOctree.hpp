#ifndef POINT_OCTREE_HPP
#define POINT_OCTREE_HPP 

#include <set>
#include <list>
#include <array>
#include <stack>
#include <queue>
#include <functional>
#include <cmath>

#include <iostream>

#include "Point.hpp"

/*
    y
    
1  | 0
-----  x
2  | 3

5 | 4
-----
6 | 7

*/


namespace qoaed {
template <class Value, class CoordType = long>
class PointOctree {
	public:
	  using value_type = Value;
	  using reference = Value&;
	  using const_reference = Value const&;
	  using Point = Point3D<CoordType>;	

	private: 

	  class Node;

	  class Node {
	  public:
	    Point   point;
	    Node*   parent;
	    Node*   childs[8];
	    mutable Value val;
	    bool deleted = false;

	    Node(const Point& p, const Value& val) : 
		point(p), parent(0), val(val) { 
		  for (int i = 0; i < 8; ++i)
		    childs[i] = 0;
		}

	    Node(const CoordType& x, const CoordType& y, const CoordType& z, const Value& val):
		point(x,y,z), parent(0), val(val) { 
		  childs = new Node*[8];
		  for (int i = 0; i < 8; ++i)
		    childs[i] = 0;
		}
  };

public:
  
	class NodeVisitor {
	  friend class PointOctree;

	private:
		Node* n;

	public:
		NodeVisitor(Node* n): n(n) {}
	    
		const CoordType& get_x() const { return n->point.x; }
		const CoordType& get_y() const { return n->point.y; }
		const CoordType& get_z() const { return n->point.z; }
		const Point& get_point() const { return n->point; }
		Value& operator*() const { return n->val; }
		operator    bool() const { return (bool) n; }
	};

private:
	Node* m_root;

public:
	PointOctree() : m_root(nullptr) {}
	~PointOctree() = default;

	void insert(const Point& p, const Value& val) {
		Node** tmp    = 0;
		Node*  parent = 0;
		if (find(p, tmp, parent)) return;   

		Node* n   = new Node(p, val);
		(*tmp)    = n;
		n->parent = parent;
	}

	void insert(const CoordType& x, const CoordType& y, const CoordType& z, const Value& val) { insert(Point(x,y,z), val); }

	NodeVisitor find(const Point& p) {
		Node** tmp    = 0;
		Node*  parent = 0;
		find(p, tmp, parent);
		return NodeVisitor(*tmp);
	}

	NodeVisitor find(const CoordType& x, const CoordType& y, const CoordType& z) { return find(Point(x,y,z)); }


	void visit_dfs(const std::function<void (const NodeVisitor&)>& visitor, NodeVisitor start = NodeVisitor(0)) {
		if (!m_root) return;

		std::stack<Node*> cont;
		if (!start)
			start.n = m_root;

		cont.push(start.n);
		Node* tmp;
		while (!cont.empty() && tmp->deleted == false) {
			tmp = cont.top();
				cont.pop();

			if (visitor)
			  visitor(start.n = tmp);

			for (int ii = 0; ii < 8; ++ii)
			  if (tmp->childs[ii])
			    cont.push(tmp->childs[ii]);
		}
	}

	void visit_bfs(const std::function<void (const NodeVisitor&)>& visitor, NodeVisitor start = NodeVisitor(0)) {
		if (!m_root) return;

		std::queue<Node*> cont;
		if (!start)
			start.n = m_root;

		cont.push(start.n);
		Node* tmp;
		while (!cont.empty()) {
			tmp = cont.front();
				cont.pop();

			visitor(start.n = tmp);

			for (int ii = 0; ii < 8; ++ii)
			  if (tmp->childs[ii])
			    cont.push(tmp->childs[ii]);
		}
	}
	/*
	NodeVisitor delete_(const CoordType& x, const CoordType& y, const CoordType& z) { return find(Point(x,y,z)); }
	
	bool delete_(const Point& p, Node**& node, Node*& parent) {
		node   = std::addressof(m_root);   
		parent = nullptr; 
		while (*node) {
		if ((*node)->point == p){
			(*node)->deleted = true;
			return true;
		}
		parent = (*node);
		node   = std::addressof((*node)->childs[what_octant(p, *node)]);
		}
		return false;
	}
	*/
private:

	bool find(const Point& p, Node**& node, Node*& parent) {
		node   = std::addressof(m_root);   
		parent = nullptr; 
		while (*node) {
		if ((*node)->point == p) return true;
		parent = (*node);
		node   = std::addressof((*node)->childs[what_octant(p, *node)]);
		}
		return false;
	}

	int what_octant(const Point& p, Node* orig) {
		if (p.x >= orig->point.x) {
			if (p.y >= orig->point.y) {
			  if (p.z >= orig->point.z)
			    return 0;
			  else
			    return 4;
		} else {
			  if (p.z >= orig->point.z)
			    return 3;
			  else
			    return 7;
		}
		} else {
			if (p.y >= orig->point.y) {
			  if (p.z >= orig->point.z)
			    return 1;
			  else 
			    return 5;
		} else {
			  if (p.z >= orig->point.z)
			    return 2;
			  else 
			    return 6;
		}
		}
	}

public:

	double distance(Point a,Point b)
	{
	 	return sqrt(pow(b.x-a.x,2.0)+pow(b.y-a.y,2.0)+pow(b.z-a.z,2.0)); 
	}
     
};
}
#endif
