
public class QuickUnionUF{
    public static void main(String[] args)
    {
        QuickUnion Qa = new QuickUnion(13);
        Qa.union(2, 9);
        Qa.union(3, 4);
        Qa.union(4, 9);
        Qa.union(6, 9);
        Qa.union(5, 6);
        Qa.union(12, 3);
        System.out.println(Qa.find(4));
        
    }
}


class QuickUnion {
    private int[] id;

    public QuickUnion(int N)
    {
        id = new int[N];
        for(int i=0; i<N; i++)
            id[i]=i;
    }

    private int findRoot(int i)
    {
        while(i!=id[i]) i = id[i];
        return i;
    }

    public boolean connected(int p, int q)
    {
        return findRoot(p)==findRoot(q);
    }

    public void union(int p, int q)
    {
        p = findRoot(p);
        q = findRoot(q);
        id[p] = q;
    }
    public int find(int i)
    {
        
        int j=0;
        int[] component = new int[id.length];
        int larger=i;
        for(int a=0; a<id.length; a++)
        {
            if(connected(i, id[a]))
            {
                component[j]=a;
                if(larger<a) larger=a;
                j++;
            }
        }
    
        
        return larger;
    }

}
