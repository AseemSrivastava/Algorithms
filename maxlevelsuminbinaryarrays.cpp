void min_sum(Node *root,unordered_map<int,int>&m,int level)
    {
        if(!root)return;
        m[level]+=root->data;
        min_sum(root->left,m,level+1);
        min_sum(root->right,m,level+1);
    }
/*You are required to complete below method */
int maxLevelSum(Node* root) {
     unordered_map<int,int>m;
        int min_level,minn=INT_MIN;
        min_sum(root,m,0);
        for(auto i = m.begin();i!=m.end();++i)
        {
            if(i->second>minn)
            {
                minn = i->second;
                min_level = i->first;
            }
        }
        return minn;
}