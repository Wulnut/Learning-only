import javax.swing.event.TableModelListener;
import javax.swing.table.TableModel;

public class KCBdata implements TableModel {

    private String[] title = {"周一", "周二", "周三", "周四", "周五", "周六", "周日"};
    private String[][] data = new String[8][7];

    public KCBdata() {
        for (int i = 0; i < data.length; ++ i) {
            for (int j = 0; j < data[i].length; ++j) {
                data[i][j] = "";
            }
        }
    }

    @Override
    public int getRowCount() {
        return data.length;
    }

    @Override
    public int getColumnCount() {
        return data[0].length;
    }

    @Override
    public String getColumnName(int columnIndex) {
        return title[columnIndex];
    }

    @Override
    public Class<?> getColumnClass(int columnIndex) {
        return String.class;
    }

    @Override
    public boolean isCellEditable(int rowIndex, int columnIndex) {
        return true;
    }

    @Override
    public Object getValueAt(int rowIndex, int columnIndex) {
        return data[rowIndex][columnIndex];
    }

    @Override
    public void setValueAt(Object aValue, int rowIndex, int columnIndex) {
            data[rowIndex][columnIndex] = (String)aValue;
    }

    @Override
    public void addTableModelListener(TableModelListener l) {

    }

    @Override
    public void removeTableModelListener(TableModelListener l) {

    }
}
