typedef struct node
{
    int data;
    node* l;
    node* r;
};

node* head = NULL;

node* getNode(int v)
{
    node* temp = new node();
    temp->data = v;
    temp->l = NULL;
    temp->r = NULL;
    return temp;
}

void insert(int v)
{
    if(head == NULL)
    {
        head = getNode(v);
    }else
    {
        node* temp = head;
        while(1)
        {
            if(v <= temp->data)
            {
                if(temp->l == NULL)
                {temp->l = getNode(v);break;}
                else
                temp = temp->l;
            }
            else
            {
                if(temp->r == NULL)
                {temp->r = getNode(v);break;}
                else
                temp = temp->r;
            }
        }
    }
}

pair<int,int> hd(node* nn)
{
    if(nn == NULL)
    return {0,0};//{h,d}
    pair<int,int>ans;
    pair<int,int>left_data = hd(nn->l);
    pair<int,int>right_data = hd(nn->r);
    int lh,rh,ld,rd,height,diameter;
    lh = left_data.X;
    rh = right_data.X;
    ld = left_data.Y;
    rd = right_data.Y;
    height = 1 + max(lh,rh);
    diameter = max( lh+rh , max(ld,rd) );
    return {height,diameter};
}

//Solved this Problem : binary-search-tree/practice-problems/algorithm/monk-watching-fight/description/
