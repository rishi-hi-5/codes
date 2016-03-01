package app.deutsche.dbglean;

import android.app.Fragment;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;

/**
 * Created by rishi on 26/6/15.
 */
public class recentSearches extends Fragment {
    public static recentSearches newInstance()
    {
        recentSearches recSearchFragment=new recentSearches();
        return recSearchFragment;
    }
    public recentSearches()
    {}
    @Override
    public View onCreateView(LayoutInflater inflater,ViewGroup container,Bundle savedInstanceState)
    {
        View rootView=inflater.inflate(R.layout.fragment_recent_searches,container,false);
        return rootView;
    }
}
