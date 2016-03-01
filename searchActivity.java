package app.deutsche.dbglean;

import android.app.Fragment;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;

/**
 * Created by rishi on 26/6/15.
 */
public class searchActivity extends Fragment {
    public static searchActivity newInstance()
    {
        searchActivity recSearchFragment=new searchActivity();
        return recSearchFragment;
    }
    public searchActivity()
    {}
    @Override
    public View onCreateView(LayoutInflater inflater,ViewGroup container,Bundle savedInstanceState)
    {
        View rootView=inflater.inflate(R.layout.fragment_search_activity,container,false);
        return rootView;
    }
}
