// RESUMO MARATONA PROGRAMAÇÃO

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())

const int INF = 1e9 + 7;
const ll LINF = 1e18 + 7;
const int MOD = 1e9 + 7;

const int MAXN = 100005;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t; // num casos de teste
    while (t--) { }

    int n;
    while (cin >> n) { } // Ler até o fim do arquivo
    
    vector<int> v;
    v.push_back(10);
    v.pop_back();
    int tamanho = v.size();
    for (int x : v) { }
    v[0]; // subscript 

    vector<pair<int, int>> vp;
    vp.push_back({1, 2});

    map<string, int> freq;
    freq["br"] = 5;
    for (auto par : freq) {
        cout << par.first << ": " << par.second; }

    // Maior elemento no topo (Padrão), util para Dijkstra.
    priority_queue<int> pq_max;
    pq_max.push(10);    pq_max.push(30);
    cout << pq_max.top(); // 30
    pq_max.pop();

    // Menor elemento no topo (Truque)
    priority_queue<int, vector<int>, greater<int>> pq_min;

    // algoritmos
    vector<int> v = {5, 2, 8, 1, 9};

    // 1. Ordenação (O(N log N))
    sort(all(v)); // v: {1, 2, 5, 8, 9}
    sort(v.begin(), v.end(), greater<int>()); // decrescente
    sort(v.begin(), v.end(), [](int a, int b) { return a > b; });

    // 2. Busca Binária (O(log N)) - REQUER ORDENAÇÃO
    // lower_bound: Primeiro elemento >= X
    auto it = lower_bound(v.begin(), v.end(), 5);
    int indice = it - v.begin(); // indice = 2

    // 3. Inverter vetor ou string
    reverse(v.begin(), v.end());

    // 4. Maior e Menor valor de um array
    int max_val = *max_element(v.begin(), v.end());
    int min_val = *min_element(v.begin(), v.end());

    ll sum = accumulate(v.begin(), v.end(), 0LL); // soma elementos

    // gcd(a, b); // MDC
    // lcm(a, b); // MMC
    // pow(a, b); // a^b
    // sqrt(a);
    // cbrt(a); // cubica
    // hypot(x, y)
    // sin(x), cos(x), tan(x), asin(x), acos(x), atan2(x, y)
    // floor(x), ceil(x), round(x)

    // isalpha(ch), isdigit(ch), isspace(ch), islower(ch), isupper(ch)

    double val1 = 0.123421;
    cout << fixed << setprecision(1) << val1 << endl;
    double* ptr = &val1;

    return 0;
}

// ALGORITOMOS ESSENCIAIS

vector<int> adj[MAXN]; // Lista de adjacência
bool vis[MAXN];        // Array de visitados

void dfs(int u) {
/// explorar mapas e labirintos. Vai o mais fundo possível antes de voltar.
    vis[u] = true;
    for (int v : adj[u])
        if (!vis[v])
            dfs(v);
}

int dist[MAXN]; // Guarda a distância da origem até cada vértice

void bfs(int start) {
/// encontrar a menor distância em grafos sem peso
    memset(dist, -1, sizeof(dist)); // Inicializa com -1 (não visitado)
    queue<int> q;
    q.push(start);
    dist[start] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u])
            if (dist[v] == -1) { // Se não foi visitado
                dist[v] = dist[u] + 1;
                q.push(v);
            }
    }
}

vector<pair<int, int>> adj2[MAXN]; // {vizinho, peso da aresta}
ll dist2[MAXN];

void dijkstra(int start) {
    for(int i = 0; i < MAXN; i++) dist2[i] = LINF;
    // priority_queue min-heap: {distancia_acumulada, vertice}
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
    
    dist[start] = 0;
    pq.push({0, start});
    
    while(!pq.empty()) {
        ll d = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        
        if (d > dist[u]) continue;
        
        for (auto edge : adj2[u]) {
            int v = edge.first;
            ll peso = edge.second;
            
            if (dist[u] + peso < dist2[v]) {
                dist2[v] = dist2[u] + peso;
                pq.push({dist2[v], v});
            }
        }
    }
}

int exemplo_uso_dijkstra() {
    int N = 4; // Total de 4 cidades

    // limpar grafo antes de usar
    for(int i = 0; i <= N; i++) adj2[i].clear();

    adj2[1].push_back({2, 10}); // 1 -> 2 peso=10
    adj2[2].push_back({3, 5}); // 2 -> 3 peso=5

    dijkstra(1); // partindo do 1
    cout << dist[3] << "\n"; // 15 (1 -> 2 -> 3)
    if (dist[4] == INF) { cout << "Sem ligação\n"; }
    return 0;
}

// UNION-FIND (Disjoint Set Union - DSU) ---
int pai[MAXN], tamanho[MAXN];

// 1. Inicializar cada elemento sozinho no seu grupo
void build(int n) {
    for(int i = 1; i <= n; i++) {
        pai[i] = i;
        tamanho[i] = 1;
    }
}

// 2. Encontrar o chefe do grupo (com compressão de caminho O(1))
int find(int x) {
    if (pai[x] == x) return x;
    return pai[x] = find(pai[x]);
}

// 3. Unir dois grupos
void join(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return; // Já estão no mesmo grupo
    
    if (tamanho[a] < tamanho[b]) swap(a, b);
    pai[b] = a;
    tamanho[a] += tamanho[b];
} 

int ex_uso_dsu() {
    int N = 5;
    build(N);

    join(1, 2); join(3, 4); join(2, 5);

    // verificar conexão entre elementos
    if (find(1) == find(5))
        cout << "1 e 5 conectados\n";  // 1 - 2 - 5

    
    return 0;
}
// ---


/// MATEMATICA
// Crivo de Eratóstenes - todos os números primos até N
bool is_prime[MAXN];
vector<int> primos;

void crivo(int n) {
    memset(is_prime, true, sizeof(is_prime));
    is_prime[0] = is_prime[1] = false;

    for (ll p = 2; p * p <= n; p++)
        if (is_prime[p])
            for (ll i = p * p; i <= n; i += p)
                is_prime[i] = false;

    // Salvar primos encontrados
    for (int p = 2; p <= n; p++)
        if (is_prime[p])
            primos.push_back(p);
}

// Exponenciação Rápida Modular // Calcula base^{exp} (mod m)
ll fast_pow(ll base, ll exp, ll mod) {
    ll res = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % mod; // Se for ímpar
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

// Função que testa se o valor 'mid' é válido para o problema
bool valida(ll mid) {
    // Lógica do problema aqui
    return true; 
}

// Busca Binária Customizada para achar menor valor que satisfaça regra
ll busca_binaria(ll max_val) {
    ll left = 0, right = max_val, ans = -1;
    
    while (left <= right) {
        ll mid = left + (right - left) / 2;
        
        if (valida(mid)) {
            ans = mid;       // Achou uma resposta possível
            right = mid - 1; // Tenta achar uma resposta MENOR
        } else
            left = mid + 1;  // Valor inválido, precisa ser MAIOR
    }
    return ans; // Retorna a melhor resposta encontrada
}

struct SegTree {
    int n;
    vll tree;

    SegTree(int n) : n(n), tree(4 * n, 0) {}

    void update(int node, int start, int end, int idx, ll val) {
        if (start == end) {
            tree[node] = val;
            return;
        }
        int mid = (start + end) / 2;
        if (start <= idx && idx <= mid)
            update(2 * node, start, mid, idx, val);
        else
            update(2 * node + 1, mid + 1, end, idx, val);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    ll query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) return 0; // Valor neutro para soma
        if (l <= start && end <= r) return tree[node];
        int mid = (start + end) / 2;
        return query(2 * node, start, mid, l, r) + query(2 * node + 1, mid + 1, end, l, r);
    }

    // Wrappers para simplificar a chamada
    void update(int idx, ll val) { update(1, 0, n - 1, idx, val); }
    ll query(int l, int r) { return query(1, 0, n - 1, l, r); }
};


namespace tree{
    struct node{
        std::string value;
        node *left;
        node *right;
    };

    node *create_node(const std::string &str_value){
        node *p = new node;
        p->value = str_value;
        p->left = nullptr;
        p->right = nullptr;

        return p;
    }

    //Função que retornar o tamanho da árvor
    int height(node *root){
        if(root == nullptr){
            return -1; }
        return std::max(height(root->left),height(root->right))+1;
    }

    void show(node *root, int ident = 0) {
        int identl = ident;
        int identr = ident;
        if (root == nullptr) return;
        std::cout << root->value << "\n";
        if (root->left != nullptr) {
            identl++;
            std::cout << std::string(identl,' ') << "l: ";
            show(root->left, identl);
        }
        if (root->right != nullptr) {
            identr++;
            std::cout << std::string(identr, ' ') << "r: ";
            show(root->right, identr);
        }
        return;
    }

    void DFS_pre(node *root){ //Percorrer em pré ordem
        if(!root) return;
        std::cout << root->value << ' ';
        DFS_pre(root->left);
        DFS_pre(root->right);
    }

    void DFS_in(node *root){ //Percorrer em in order
        if(!root) return;
        DFS_in(root->left);
        std::cout<< root->value << ' ';
        DFS_in(root->right);
    }

    void DFS_post(node *root){ //Percorrer em post order
        if(!root) return;
        DFS_post(root->left);
        DFS_post(root->right);
        std::cout << root->value << ' ';
    }

    void BSF(node *root){ //Percorre em largura
        if(!root) return;
        std::queue<node *> fila;
        fila.push(root);
        while(!fila.empty()){
            node *aux = fila.front();
            std::cout << aux->value << ' ';
            fila.pop();
            if(aux->left)
                fila.push(aux->left);
            if(aux->right)
                fila.push(aux->right);        
        }
    }

    //implementa a inserção em uma árvore binária de pesquisa
    void BST_insert(node * &root, const std::string &val){
        if(!root)
            root = create_node(val);
        else if(val < root->value)
            BST_insert(root->left,val);
        else
            BST_insert(root->right,val);    
    }

    //Pesquisar um valor na BST
    // se encontrar: Retornar o pointer para o node
    // se ñ encontrar: retorna nullptr
    node* BST_find(node * &root, const std::string &val){
        if (!root || root->value == val)
            return root;
        if (root->value > val) {
            return BST_find(root->left, val); }
        if (root->value > val) {
            return BST_find(root->right, val); }
    }

    int count_leaves(node *root) {
        if (!root) return 0;
        int somaFolhasFilhos = 0;

        if (!root->left && !root->right) return 1;
        somaFolhasFilhos += count_leaves(root->left);
        somaFolhasFilhos += count_leaves(root->right);
        return somaFolhasFilhos;
    }
}

/// biblioteca para grafos
namespace graph {
class digraph {
    private:
        struct node {
            std::string value;
            std::vector<node *> links; };

        std::unordered_map<std::string, node> nodes;
        std::unordered_set<node *> visited;

    public:
        void insert_nodo(const std::string &s) {
            node aux;
            aux.value = s;
            nodes[s] = aux;
        }

        size_t size() {
            return nodes.size(); }

        node *find(const std::string &s) {
            auto it = nodes.find(s); // find do unnorderedmap
            return it == nodes.end() ? nullptr : &it->second;
        }
        
        bool insert_link(const std::string &from, const std::string &to) {
            auto pfrom = find(from);
            if (pfrom == nullptr)
                return false;
            auto pto = find(to);
            if (pto == nullptr)
                return false;
            for (auto link : pfrom->links)
                if (link == pto)
                    return false;
            pfrom->links.push_back(pto); // Adiciona a aresta na lista de adjacencia
            return true;
        }

        size_t degree(const std::string &n) {
            auto p = find(n);
            if (p == nullptr) return 0;
            return indegree(n) + outdegree(n);
        }
        
        size_t indegree(const std::string &n) {
            auto p = find(n);
            if (p == nullptr) return 0;

            size_t qtd = 0;
            for (auto vertices : nodes)
                for (auto link : vertices.second.links)
                    if (link->value == n) qtd++;
            return qtd;
        }

        size_t outdegree(const std::string &n) {
            auto node = find(n);
            if (node->value == n) {
                return node->links.size(); }
            return 0;
        }

        int totalArestas(){
          int arestas = 0;
          for (auto nd : nodes)
              arestas += outdegree(nd.first);

          return arestas;
        }

        size_t calc_diametro() {
            size_t diametroMax = 0;
            for (auto nd : nodes) {
                size_t current_diameter = BFS_max_distance(nd.first);
                diametroMax = std::max(diametroMax, current_diameter);
            }
            return diametroMax;
        }

        size_t BFS_max_distance(const std::string &s) {
            auto p = find(s);
            if (!p)
                return 0;
            visited.clear();
            std::queue<node *> fila;

            fila.push(p);
            visited.insert(p);

            size_t maxDistance = 0;
 
            while (!fila.empty()) {
                auto size = fila.size();
                bool achou = false;
                for (auto i = 0; i < size; i++) {
                    auto current = fila.front();
                    fila.pop();

                    for (auto vizinho : current->links) {
                        if (visited.find(vizinho) == visited.end()) {
                            visited.insert(vizinho);
                            fila.push(vizinho);
                            achou = true;
                        }
                    }
                }
                if (achou) { maxDistance++; }
            }
            return maxDistance;
        }

        void remove_link(const std::string &from, const std::string &to) {
            auto pfrom = find(from);
            if (!pfrom)
                return;
            auto pto = find(to);
            if (!pto)
                return;
            // Verifica se o destine esta na lista dos vizinhos da origem
            auto it = std::find(pfrom->links.begin(), pfrom->links.end(), pto);
            if (it == pfrom->links.end())
                return;             // Não é vizinho da origem
            pfrom->links.erase(it); // É vizinho será excluído
        }

        void remove_node(const std::string &key) {
            auto pkey = find(key);
            if (!pkey)
                return;
            for (auto vertice : nodes)
            { // for auto &[k,nd] : nodes ja pega o first e second
                remove_link(vertice.second.value, key);
            }
            nodes.erase(key);
            return;
        }
        
        void recursive_DFS(node *p, int level = 0) {
            if (visited.count(p)) // Já foi visited
                return;
            std::cout << std::string(level, '\t') << p->value << std::endl;
            visited.insert(p);
            for (auto in : p->links) {
                recursive_DFS(in, level + 1); }
        }

        void DFS_from(const std::string &s) {
            auto p = find(s); // Our find
            if (!p)
                return;
            visited.clear();
            recursive_DFS(p);
        }

        void BFS_from(const std::string &s) {
            auto p = find(s);
            if (!p)
                return;
            visited.clear();
            std::queue<node *> q;
            q.push(p);
            visited.insert(p);
            while (!q.empty()) {
                auto current = q.front();
                q.pop();
                std::cout << current->value << " ";
                for (auto vizi : current->links) {
                    if (visited.count(vizi) == 0) {
                        q.push(vizi);
                        visited.insert(vizi);
                    }
                }
            }
            std::cout << "\n";
        }

        std::vector<std::string> shortest_path(const std::string &from, const std::string &to) {
            std::vector<std::string> path;
            auto pfrom = find(from); // Our find
            if (pfrom == nullptr)
                return path;
            auto pto = find(to);
            if (pto == nullptr)
                return path;
            // node pointer
            std::unordered_map<node *, node *> source;
            std::queue<node *> queue;
            queue.push(pfrom);
            source[pfrom] = nullptr;
            bool found_path = false;
            while (!queue.empty()) {
                auto current = queue.front();
                queue.pop();
                if (current == pto) {
                    found_path = true;
                    break;
                }
                for (auto &vizi : current->links) {
                    // Count how many times vizi is in source
                    if (source.count(vizi) == 0) {
                        queue.push(vizi);
                        source[vizi] = current;
                    }
                }
            }
            if (found_path) {
                auto p = pto;
                while (p != nullptr)
                {
                    path.push_back(p->value);
                    p = source[p];
                }
                std::reverse(path.begin(), path.end());
            }
            return path;
        }

        bool existe_link(const std::string &from, const std::string &to) {
            auto pfrom = find(from); // Our find
            if (pfrom == nullptr)
                return false;
            auto pto = find(to);
            if (pto == nullptr)
                return false;

            for (auto link : pfrom->links)
            {
                if (link == pto)
                {
                    return true;
                }
            }
            return false;
        }

    }; /// fim da classe digraph

} // fim do namespace