#include <fstream>
#include <cstdlib>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <iostream>

namespace graph
{
    class digraph 
    {

        private:
        struct node {
            std::string value;
            std::vector<node*> links;
        };

        std::unordered_map<std::string,node> nodes;
        std::unordered_set<node*> visited;

        public:
        void insert_node (const std::string& s) {
            node aux;
            aux.value = s;
            nodes[s] = aux;
        }

        size_t size () {
            return nodes.size();
        }

        node* find (const std::string& s) {
            auto it = nodes.find(s);
            return (it == nodes.end()) ? nullptr : &it->second;
        }

        bool insert_link ( const std::string& from, const std::string& to )
        {
            auto pfrom = find(from);
            if (!pfrom) return false;

            auto pto = find(to);
            if (!pto) return false;

            pfrom->links.push_back(pto);
            return true;
        }

        void export2dot (const std::string& filename)
        {
            std::ofstream dot(filename);
            dot << "digraph{\n";

            for ( auto nd : nodes ) {
                dot << "\t" << nd.first;
                if ( nd.second.links.size() > 0 ) 
                {
                    dot << " -> {";

                    for ( auto neighbour : nd.second.links ) 
                        dot << neighbour->value << " ";

                    dot << "}";
                }
                dot << ";\n";
            }
            dot << "}\n";
        }

        void draw (std::string filename)
        {
            filename.append(".dot");
            export2dot(filename);

            std::string command = "dot -Tx11 ";
            command.append(filename);

            const char* c_command = command.c_str();
            std::system(c_command);
        }

        size_t indegree (std::string node)
        {
            if (!find(node)) return 0;

            size_t cnt = 0;
            for ( auto v : nodes ) 
                for ( auto l : v.second.links ) 
                    if ( l->value == node ) cnt++;
            return cnt;
        }

        size_t outdegree (std::string node) { 
            auto p = find(node);
            return !p ? 0 : p->links.size();
        }

        size_t degree (std::string node) {
            return (find(node)) ? indegree(node) + outdegree(node) : 0;
        }

        void remove_link (const std::string &from, const std::string &to) 
        {
            auto pfrom = find(from);
            if (!pfrom) return;

            auto pto = find(to);
            if (!pto) return;

            auto it = std::find( pfrom->links.begin(), pfrom->links.end(), pto );

            if (it == pfrom->links.end()) return;

            pfrom->links.erase(it);
        }

        void remove_node (const std::string &key)
        {
            auto target = find(key);
            if (!target) return;

            for ( auto &[k,nd] : nodes )
                remove_link( nd.value, key);
                // auto it = std::find( nd.links.begin(), nd.links.end(), target );

                // if (it != nd.links.end()) // if node was found
                //     nd.links.erase(it);
            nodes.erase(key);
        }

        void DFS(node *p, int level = 0)
        {
            if (visited.count(p)) return;

            std::cout << std::string(level, '\t')
                      << p->value << std::endl;
            visited.insert(p);

            for (auto l : p->links) 
                DFS(l, level + 1);
        }

        void DFS_from (const std::string& s)
        {
            auto p = find(s);
            if (!p) return;
            DFS(p);
        }

    }; // end of class
    
}