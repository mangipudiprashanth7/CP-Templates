#define ll long long
// Modular Inverse Works When m,a are coprime, So gcd(a,m)=1.
ll xgcd(ll a,ll b,ll &x,ll &y)
{
    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }
    ll x1,y1;
    ll g = xgcd(b,a%b,x1,y1);
    x = y1;
    y = x1 - y1*(a/b);
    return g;
}

ll mod_inv(ll a,ll m)
{
    ll x,y;
    ll g = xgcd(a,m,x,y);
    if(g!=1)
    return -1;
    x = (x%m + m)%m;//x can be negative but we need possitive
    return x;
}

ll mod_div(ll a,ll b,ll m)
{
    ll inv = mod_inv(b,m);
    if(inv == -1)
    return -1;
    else
    return (inv*a)%m;// (a * b^-1)%m
}
