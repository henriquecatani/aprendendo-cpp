#include <iostream>
#include <fstream>
#include <cstdlib>
#include <unordered_map>
#include <string>
#include <vector>

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
            auto pto = find(to);
            if ( !pto || !pfrom ) return false; // origem ou destino n existe

            pfrom->links.push_back(pto);
            return true;
        }

    };
    
}